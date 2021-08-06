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
    // 60↓F 60+D 70+C 80+B 90+A 100A++
    vector<string> scores = {"F","D","C","B","A","A++"};
    int grade;
    string lettergrade;
    while (cin >> grade) {
        int index = ((grade / 10 - 5) < 0) ? 0 : (grade / 10 - 5);
        lettergrade = scores[index];
        if (grade >= 60 && grade <100) {
            lettergrade += (grade % 10 < 3) ? "-" : ( (grade % 10 > 7) ? "+" : "" );
        }
        cout << lettergrade << endl;
    }
}
