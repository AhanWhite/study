#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string opt;
    cout << "读取多个(1)或多行(2)：" ;
    cin >> opt;
    if (opt == "1") {
        string s;
        while(cin >> s)
            cout << s << endl;
    } else if (opt == "2") {
        string s;
        while(getline(cin, s))
            cout << s << endl;
    }
    return 0;
}
