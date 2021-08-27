#include <iostream>
#include <vector>

using std::endl;
using std::cin;
using std::cout;
using std::vector;

int add(const int &a, const int &b){
    return a+b;
}
int sub(const int &a, const int &b){
    return a-b;
}
int mul(const int &a, const int &b){
    return a*b;
}
int div(const int &a, const int &b){
    return a/b;
}


int main()
{
    int a, b;
    char op;
    cout << "Enter an expression(such as 'a + b'): ";
    cin >> a >> op >> b;
    int index = 0;
    switch(op) {
        case '+':
            index = 0;
            break;
        case '-':
            index = 1;
            break;
        case '*':
            index = 2;
            break;
        case '/':
            index = 3;
            break;
    }
    vector<int (*) (const int &, const int &) > fv = {add, sub, mul, div};
    cout << a << " " << op << " " << b << " = " << fv[index](a, b) << endl;
}
