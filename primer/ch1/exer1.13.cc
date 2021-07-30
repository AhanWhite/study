#include <iostream>

int main()
{
    int sum = 0;
    // 只要val的值小于等于10，while循环就会继续执行
    for (int val = 50; val <= 100; ++ val) {
        sum += val; // 将sum + val 赋予sum
    }
    std::cout << "1.13-1 Sum of 1 to 10 inclusive is "
              << sum << std::endl;

    std::cout << "1.13-2:" << std::endl;
    for (int sum = 10; sum >= 0; --sum) {
        std::cout << sum << std::endl;
    }


    int val1 = 0, val2 = 0;
    std::cout << "1.13-2 Enter two numbers: ";
    std::cin >> val1 >> val2;
    if (val2 < val1) {
        int mid = val1;
        val1 = val2;
        val2 = mid;
    }
    for (; val2 >= val1; --val2) {
        std::cout << val2 << std::endl;
    }

    return 0;
}
