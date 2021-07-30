#include <iostream>

int main()
{
    int sum = 0, value = 0;
    // 读取数据直到遇见文件尾，计算所有读入值的和
    while (std::cin >> value) {
        sum += value; //等价于sum = sum + value
    }
    std::cout << "Sum is " << sum << std::endl;
    return 0;
}
