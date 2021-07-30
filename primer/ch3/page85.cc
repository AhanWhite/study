#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string hex="0123456789abcdef";
    decltype(hex.size()) index;
    while (cin >> index) {
        if (index >=0 && index < 16)
            cout << hex[index];
        else
            cout << "Error, number(0-15)."
    }
    cout << endl;
}
