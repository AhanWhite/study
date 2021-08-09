#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string s, spre;
    bool flag = false;
    while (cin >> s) {
        if (s == spre) {
            flag = true;
            break;
        }
        spre = s;
    }
    cout << (flag ? "repetition: " + spre : "none repetition") << endl;
}
