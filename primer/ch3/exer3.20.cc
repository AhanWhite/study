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
    vector<int> ivec;
    int num, len;
    while (cin >> num)
        ivec.push_back(num);
    for (int i = 0; i <= ivec.size()/2; ++i) {
        if (ivec.size() < 2*i+1)
            cout << ivec[2*i] << " ";
        else
            cout << ivec[2*i] + ivec[2*i+1] << " ";
    }
    cout << endl;
    for (int i = 0; i < ivec.size(); ++i) {
        if (i == ivec.size()-1-i)
            cout << ivec[i] << " ";
        else
            cout << ivec[i] + ivec[ivec.size()-1-i] << " ";
    }
    cout << endl;
}
