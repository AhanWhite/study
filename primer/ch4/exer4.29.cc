#include <iostream>

using std::cout;
using std::endl;


int main()
{
    int x[10], *p = x;
    cout << "指针长度为8" << endl;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;
}
