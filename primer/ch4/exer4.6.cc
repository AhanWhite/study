#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int number;
    cout << "Input a number: ";
    cin >> number;
    cout << (number%2 ? "奇数" : "偶数") << endl;
}
