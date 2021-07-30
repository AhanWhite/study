#include <iostream>

int main()
{
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        std::cout << "循环：" << i << std::endl;
        sum += i;
    std::cout << i << " " << sum << std::endl;
    return 0;
}
