#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string sa[10];
int ia[10];
int main()
{
    string  sa2[10];
    int     intarr[10];

    for (auto i: sa)
        cout << "sa " << i << endl;
    for (auto i: ia)
        cout << "ia " << i << endl;
    for (auto i: sa2)
        cout << "sa2 " << i << endl;
    for (auto iaa2: intarr)
        cout << "ia2 " << iaa2 << endl;
}
