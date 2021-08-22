#include <iostream>
#include "../include/array/array.h"
#include "../include/vector/vector.h"
#include <array>

class Vector3 {
public:
    float x, y, z;
    int *m_memoryBlock;

public:
    Vector3() = default;
    Vector3(float scalar)
        :x(scalar), y(scalar), z(scalar) {
        m_memoryBlock = new int[5];
    }
    Vector3(float x, float y, float z)
        :x(x), y(y), z(z) {
        m_memoryBlock = new int[5];
    }


    Vector3(const Vector3 &other) = delete;

    Vector3(Vector3&& other) noexcept
        :x(other.x), y(other.y), z(other.z) {
        m_memoryBlock = other.m_memoryBlock;
        other.m_memoryBlock = nullptr;
        std::cout << "Moved\n";
    }

    Vector3 &operator= (const Vector3 &other) = delete;

    Vector3 &operator= (Vector3 &&other) noexcept {
        std::cout << "Moved\n";
        x = other.x;
        y = other.y;
        z = other.z;
        m_memoryBlock = other.m_memoryBlock;
        other.m_memoryBlock = nullptr;
        return *this;
    }

    ~Vector3() {
        delete [] m_memoryBlock;
        std::cout << "Destroyed\n";
    }
};

int main() {
    std::cout << "===================test for arrays====================" << "\n";
    yongxin::array<int, 5> arr{};
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 4;

    std::cout << arr.size() << "\n";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    } std::cout << "\n";

    std::cout << "===================test for vectors===================" << "\n";
    yongxin::vector<std::string> vec;
    vec.push_back("hello");
    vec.push_back("world");
    vec.push_back("123");
    vec.push_back("1234");
    vec.push_back("1235");
    vec.push_back("1236");
    vec.push_back("1237");
    vec.push_back("1238");
    vec.push_back("1239");
    vec.push_back("1230");
    vec.push_back("1241");
    vec.push_back("1242");
    vec.push_back("1243");
    vec.push_back("1244");
    vec.push_back("1245");

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    } std::cout << "\n";

    std::cout << "===================test for vectors===================" << "\n";
    yongxin::vector<Vector3> vec2;
    vec2.push_back(Vector3(1.0f));
    vec2.push_back(Vector3(2.0f, 3.0f, 4.0f));
    vec2.push_back(Vector3());
    vec2.emplace_back(1.0f);
    vec2.clear();
    vec2.emplace_back(2.0f, 3.0f, 4.0f);
    vec2.emplace_back();

    for (int i = 0; i < vec2.size(); i++) {
        std::cout << vec2[i].x << " " << vec2[i].y << " " << vec2[i].z << "\n";
    } std::cout << "\n";
    std::cout << "==================test for iterators==================" << "\n";
    yongxin::vector<int> vec3;
    vec3.emplace_back(1);
    vec3.emplace_back(2);
    vec3.emplace_back(3);
    vec3.emplace_back(4);
    vec3.emplace_back(5);
    std::cout << "Range-based for loop:\n";
    for (int value : vec3) {
        std::cout << value << " ";
    }std::cout << "\n";

    std::cout << "Iterators:\n";
    for (yongxin::vector<int>::iterator it = vec3.begin();
         it != vec3.end(); it++) {
        std::cout << *it << " ";
    } std::cout << "\n";
    return 0;
}