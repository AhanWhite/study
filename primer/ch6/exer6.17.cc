#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

using std::string;


bool hasUpper(const string &s)
{
    for(const auto &i:s) {
        if(isupper(i))
            return true; // not 0
    }
    return false; // 0
}

void toLower(string &s)
{
    for(auto &i:s) {
        if(isupper(i))
            i = tolower(i);
    }
}

int main()
{
    string a = "hello World";
    cout << (hasUpper(a) ? "存在大写字母" : "不存在大写字母") << endl;
    toLower(a);
    cout << a << endl;
}
