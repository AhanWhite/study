#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int two_search(vector<int> *v, int number);

int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    int number;
    cin >> number;

    int res = two_search(&v, number);
    cout << res << endl;
}

int two_search(vector<int> *v, int number)
{
    auto beg = v->cbegin(), end = v->cend();
    auto mid = beg + v->size()/2;
    while (mid != end && *mid != number) {
    cout << "beg=" << *beg << "\tend=" << *end << "\tmid=" << *mid << endl;
        if (*mid > number)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg)/2;
    }
    if (mid == end) {
        cout << "没有该元素" << endl;
        return -1;
    }
    return mid - v->cbegin();
}
