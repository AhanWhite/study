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
    int i;
    vector<int> v1, v2;

    cout << "input first vector: " ;
    while (cin >> i)
        v1.push_back(i);

    // 必须加这两行清除输入流的状态，才能重新读取数据
    cin.clear();
    clearerr(stdin);

    cout << "input second vector: " ;
    while (cin >> i)
        v2.push_back(i);
    
    vector<int> &b = (v1.size() > v2.size() ? v1 : v2);
    vector<int> &s = (v1.size() < v2.size() ? v1 : v2);
    for (decltype(v1.size()) index = 0, vz = s.size(); index != vz; ++index) {
         if (s[index] != b[index]) {
            cout << "\n res: not same" << endl;
            return 1;
         }
    }
    cout << "\n res: same" << endl;
    return 0;
}
