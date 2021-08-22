#include <iostream>
#include <string>
#include <vector>

void *operator new(size_t sz) {
    std::cout << "Created!\n";
    return malloc(sz);
}

int main() {
    std::vector<std::string> svec;
    std::string str1 = "magic++";
    std::string str2 = "abc++";

    std::cout << "before: " << str1 << "\n";
    svec.push_back(std::move(str1));
    std::cout << "after: " << str1 << "\n";    

    std::cout << "before: " << str2 << "\n";
    svec.emplace_back(str2);
    std::cout << "after: " << str2 << "\n";

    for (const std::string &s : svec)
        std::cout << s << " "; 
    std::cout << "\n";

    return 0;    
}