#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s, all1, all2;
    while(cin >> s) {
        all1 += s;
        all2 += s + " ";
    }
    cout << "1. " << all1 << endl;
    cout << "2. " << all2 << endl;
}
