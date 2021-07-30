#include <iostream>

int main()
{
    int val1 = 0, val2 = 0;
    std::cout << "Enter two numbers: ";
    std::cin >> val1 >> val2;
    if (val2 < val1) {
        int mid = val1;
        val1 = val2;
        val2 = mid;
    }
    while (val2 >= val1) {
        std::cout << val2 << std::endl;
        --val2;
    }
}
