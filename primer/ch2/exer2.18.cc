#include <iostream>

int main()
{
    int i = 100, *p1 = &i;
    int j = 100, *p2 = &j;

    std::cout << "p1" << p1 << "\t" << *p1 << std::endl;
    std::cout << "p2" << p2 << "\t" <<*p2 << std::endl;

    *p1 = 10;   // 改变指针对象的值
    p2 = p1;    // 改变指针的值

    std::cout << "p1" << p1 << "\t" << *p1 << std::endl;
    std::cout << "p2" << p2 << "\t" <<*p2 << std::endl;
    return 0;
}
