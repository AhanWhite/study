#include <iostream>

int main()
{
    bool b = 42;
    std::cout << "bool b = 42;\t\t// ";
    std::cout << "b的值是\t" << b << std::endl;
    int i = b;
    std::cout << "int i = b;\t\t// ";
    std::cout << "i的值是\t" << i << std::endl;
    i = 3.14;
    std::cout << "i = 3.14;\t\t// ";
    std::cout << "i的值是\t" << i << std::endl;
    double pi = i;
    std::cout << "double pi = i;\t\t// ";
    std::cout << "pi的值是\t" << pi << std::endl;
    unsigned char c = -1;
    std::cout << "unsigned char c = -1;\t\t// ";
    std::cout << "c的值是\t" << (int)c << std::endl;
    signed char c2 = 256;
    std::cout << "signed char c2 = 256;\t\t// ";
    std::cout << "c2的值是\t" << c2 << std::endl;
}
