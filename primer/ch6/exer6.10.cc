#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void change(int *p1, int *p2);

int main()
{
    int a, b;
    cin >> a >> b;
    cout << endl;
    change(&a, &b);
    cout << a << " " << b << endl;
}


void change(int *p1, int *p2)
{
    int c = *p1;
    *p1 = *p2;
    *p2 = c;
}
