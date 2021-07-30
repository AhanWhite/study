#include <iostream>

int main()
{
    int ival = 1;
    int *pi = &ival;	// pi指向int类型整数
    int **ppi = &pi;	// ppi指向int类型指针
    
    std::cout << "1. ival  = " << ival  << std::endl;
    std::cout << "2. *pi   = " << *pi   << std::endl;
    std::cout << "3. **ppi = " << **ppi << std::endl;
}
