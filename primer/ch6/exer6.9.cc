#include "Chapter6.h"
  
using std::cout;
using std::endl;

int main()
{
  int a = 0, b = a;
  std::cin >> a >> b;
  cout << Add(a, b) << endl;
  return 0;
}
