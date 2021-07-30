#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto g = ci;

    using namespace std;
    cout << "a\t" << a << endl;
    a = 42;
    cout << "a\t" << a << endl;
    cout << "b\t" << b << endl;
    b = 42;
    cout << "b\t" << b << endl;
    cout << "c\t" << c << endl;
    c = 42;
    cout << "c\t" << c << endl;
    cout << "g\t" << g << endl;
    g = 42;
    cout << "g\t" << g << endl;
}
