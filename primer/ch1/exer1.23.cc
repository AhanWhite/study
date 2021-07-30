#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item, ret;
    if (std::cin >> item) {
        ret = item;
        while (std::cin >> item) {
            if (item.isbn() == ret.isbn()) {
                ret += item;
            } else {
                std::cout << "Sum of " << ret.isbn() << ": " << ret << std::endl;
                ret = item;
            }
        }
        std::cout << "Sum of " << ret.isbn() << ": " << ret << std::endl;
    }
    return 0;
}
