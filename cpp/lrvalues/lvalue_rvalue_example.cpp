#include <iostream>
#include <string>

/* GetRValue returns a rvalue (temporary, in registers) */
int GetRValue() { return 5; }

/* GetLValue returns a lvalue (stored in memory) */
int &GetLValue() { static int v = 5; return v; }

/* only accept lvalue */
void PrintNameLvalue(std::string &name) { std::cout << name << "\n"; }

/* only accept rvalue (temporary objects) */
void PrintNameRvalue(std::string &&name) { std::cout << name << "\n"; }

/* const std::string & here is compatible with both lvalue and rvalue */
void PrintName(const std::string &name) { std::cout << name << "\n"; }

int main() {
    int i /* lvalue */ = 10; /* rvalue */
    // normally lvalue is on the left side
    //          rvalue is on the right side
    //          but this is not always true
    // you cannot assign something to the rvalue
    int a = i;  /* assign a lvalue by a lvalue */
    // GetRValue() = 6; // you cannot do that
    std::cout << GetLValue() << "\n";
    GetLValue() = 4;
    std::cout << GetLValue() << "\n";

    // int &a = 5; // can't do that
    const int &b = 6; // correct

    std::string firstName = "San";
    std::string secondName = "Zhang";
    std::string fullName = firstName + secondName;
    PrintName(fullName);
    PrintName(firstName + secondName);

    return 0;
}