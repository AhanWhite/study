#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void version1();
void version2();
void version3();

int main()
{
    version1();
    version2();
    version3();
}

void version1(){
    cout << "===version1===" << endl;
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    for (const int (&row)[4] : ia) {
        for (int col : row)
            cout << col << " ";
        cout << endl;
    }
}
void version2(){
    cout << "===version2===" << endl;
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    for (int i = 0; i != 3; ++i) {
        for (int j = 0; j != 4; ++j)
            cout << ia[i][j] << " ";
        cout << endl;
    }
}
void version3(){
    cout << "===version3===" << endl;
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    for (int (*p)[4] = ia; p != ia + 3; ++p) {
        for (int *p2 = *p; p2 != *p + 4; ++p2)
            cout << *p2 << " ";
        cout << endl;
    }
}

