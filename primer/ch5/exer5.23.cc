#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;

int main()
{
    int a, b;
    
    while(cout << "请输入两个整数: " && cin >> a >> b) {
        try {
            if (b == 0)
                // 抛出异常
                throw runtime_error("被除数不能为0");
            cout << a/b << endl;
        // 捕捉异常
        } catch (runtime_error e) {
            cout << "something error:" << e.what() << endl;
            cout << "\nTry Again? Enter y or n: " << endl;
            char c;
            cin >> c;
            if (!c && c == 'n') {
                break;
            }
        }
    }
}
