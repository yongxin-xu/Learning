#include <iostream>

class String {
public:
    String() = default;

    String(const char *str) {
        std::cout << "Created\n"; 
        m_size = strlen(str);
        m_data = new char[m_size];
        memcpy(m_data, str, m_size);
    }

    String(const String &other) {
        std::cout << "Copied\n"; 
        m_size = other.m_size;
        m_data = new char[m_size];
        memcpy(m_data, other.m_data, m_size);
    }

    String(String &&rvalue) noexcept { 
        /* takes in a rvalue reference */
        std::cout << "Moved\n"; 
        m_size = rvalue.m_size;
        m_data = rvalue.m_data;

        rvalue.m_size = 0;
        rvalue.m_data = nullptr;
    }

    ~String() { std::cout << "Destroyed\n"; delete []m_data; }

    String &operator=(String &&rvalue) noexcept {
        if (this != &rvalue) {
            delete []m_data;
            
            printf("Moved!\n");
            m_size = rvalue.m_size;
            m_data = rvalue.m_data;

            rvalue.m_size = 0;
            rvalue.m_data = nullptr;
        }
        return *this;
    }

    void Print() {
        for (size_t i = 0; i < m_size; i++) {
            printf("%c", m_data[i]);
        }
        printf("\n");
    }

private:
    char *m_data;
    uint32_t m_size;
};

class Entity {
public:
    Entity(const String &name): m_name(name) {}
    Entity(String &&rvalue): m_name(std::move(rvalue)) {}
    void PrintName() {
        m_name.Print();
    }
private:
    String m_name;
};

int main() {
    Entity entity(String("test"));
    entity.PrintName();
    return 0;
}