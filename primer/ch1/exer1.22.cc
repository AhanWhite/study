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
                std::cout << "Error: item1 is difference with item2." << std::endl;
                std::cout << "       now, all of sum: " << ret << std::endl;
                return -1;
            }
        }
        std::cout << "Sum of all: " << ret << std::endl;
    }
    return 0;
}
