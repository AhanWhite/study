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
    int a;
    vector<int> ivec;
    while(cin >> a)
        ivec.push_back(a);
    for(auto i : ivec)
        cout << i << " ";
    cout << endl;
}
