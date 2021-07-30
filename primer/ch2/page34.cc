#include <iostream>

int main()
{
    unsigned u = 10;
    int i = -42;
    std::cout << i + i << std::endl; // 输出-84
    std::cout << u + i << std::endl; // 如果int占32位，输出

    std::cout << std::endl;

    unsigned u1 = 42, u2 =10;
    std::cout << u1 - u2 << std::endl;
    std::cout << u2 - u1 << std::endl;
    int a = 1, b = -1;
    std::cout << u1 - a << std::endl;
    std::cout << u1 - b << std::endl;

    char c = 'a';	// 'a' 字符字面值
    char d[] = "a";	// "a" 字符串字面值

    return 0;
}
