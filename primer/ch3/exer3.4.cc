#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
    {
        cout << "字符串相等" << endl;
    } else {
        cout << "1. " <<  (s1 > s2 ? s1 : s2) << endl;
    }
    if (s1.size() == s2.size()) {
        cout << "字符串长度相等" << endl;
    } else {
        cout << "2. " << (s1.size() > s2.size() ? s1 : s2) << endl;
    }
}
