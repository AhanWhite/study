#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<string> test = {"Hello, ", "world.", "Today ", "is ", "Tuesday.", "", "How ", "about ", "you?"};

    for (auto ts : test) {
        cout << ts;
        if (ts.empty() || ts[ts.size()-1] == '.')
            cout << endl;
    }
    cout << endl;
}

