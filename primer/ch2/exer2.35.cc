#include <iostream>

int main()
{
    const int i = 42;
    auto j  = i; const auto &k = i; auto *p = &i;
    const auto j2 = i, &k2 = i;


    using namespace std;
    cout << "j\t" << j << endl;
    j = 23;
    cout << "j\t" << j << endl;

    //cout << "k\t" << k << endl;
    //k = 23; // 常量引用 只读  无法更改
    //cout << "k\t" << k << endl;

    //cout << "p\t" << p << endl;
    //p = 23; // 指针常量 只读
    //cout << "p\t" << p << endl;

    //cout << "j2\t" << j2 << endl;
    //j2 = 23; // 整型常量
    //cout << "j2\t" << j2 << endl;

    //cout << "k2\t" << k2 << endl;
    //k2 = 23; // 常量引用
    //cout << "k2\t" << k2 << endl;
}
