#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "bool: \t" << sizeof(bool) << endl;
    cout << "char: \t" << sizeof(char) << endl;
    cout << "wchar_t: \t" << sizeof(wchar_t) << endl;
    cout << "char16_t: \t" << sizeof(char16_t) << endl;
    cout << "char32_t: \t" << sizeof(char32_t) << endl;
    cout << "short: \t" << sizeof(short) << endl;
    cout << "int: \t" << sizeof(int) << endl;
    cout << "long: \t" << sizeof(long) << endl;
    cout << "long long: \t" << sizeof(long long) << endl;
    cout << "float: \t" << sizeof(float) << endl;
    cout << "double: \t" << sizeof(double) << endl;
    cout << "long double: \t" << sizeof(long double) << endl;

    int a = 19999, *p = &a, &y = a;
    char b = 'c', *p1 = &b, &y1 = b;

    cout << "int a的指针: " << sizeof(p) << endl;
    cout << "int a的引用: " << sizeof(y) << endl;
    cout << "char b的指针: " << sizeof(p1) << endl;
    cout << "char b的引用: " << sizeof(y1) << endl;
}
