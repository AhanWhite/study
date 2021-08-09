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
    string s, snow, slarge;
    unsigned int now = 0, ilarge=0;
    if (cin >> s) {
        slarge = snow = s;
        ilarge = now = 1;
    }
    while (cin >> s) {
        // 如果是上一个单词 计数
        if (s == snow) {
            ++now;
            continue;
        }
        // 如果不是上一个单词，先换后更新
        if (now > ilarge) {
            slarge = snow;
            ilarge = now;
        }
        snow = s;
        now = 1;
    }
    cout << "most is " << slarge << ": " << ilarge << "times" << endl;
}
