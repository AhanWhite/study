#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int val)
{
    int ret = 1;
    while (val > 0)
        ret *= val--;

    return ret;
}

int main()
{
    int i;
    while(cin >> i) {
        cout << "Ret: " << fact(i) << endl;
    }
    return 0;
}
