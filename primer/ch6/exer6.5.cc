#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int truth(int val)
{
    return val < 0 ? -val : val;
}

int main()
{
    int i;
    while(cin >> i) {
        cout << "绝对值: " << truth(i) << endl;
    }
    return 0;
}
