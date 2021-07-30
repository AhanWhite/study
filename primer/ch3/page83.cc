#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s;
    getline(cin, s);
    decltype(s.size()) punct_count = 0;
    for (auto c : s){
        if (ispunct(c))
            punct_count++;
    }
    cout << "标点符号数量：" << punct_count << endl;
}
