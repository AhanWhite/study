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
    unsigned int a=0,e=0,i=0,o=0,u=0,other=0,tab=0,endline=0,space=0,ff=0,fl=0,fi=0;
    char ch;
    bool fFlag = false;
    while ((ch = getchar()) != -1) {
        flag = fFlag;
        switch (ch) {
            case 'f':
                if (!fFlag) {
                    fFlag = true;
                    ++other;
                    break;
                } else {
                    // 代表上一个char为f
                    fFlag = false;
                    --other;
                    ++ff;
                    break;
                }
            case 'l':
				if (fFlag)  {
                    // 代表上一个char为f
                    fFlag = false;
                    --other;
                    ++fl;
                    break;
                } else {
					++other;
					break;
				}
            case 'a': case 'A':
                ++a;
                break;
            case 'e': case 'E':
                ++e;
                break;
            case 'i': case 'I':
				if (fFlag)  {
                    // 代表上一个char为f
                    fFlag = false;
                    --other;
                    ++fi;
                    break;
                } else {
                    ++i;
                    break;
                }
            case 'o': case 'O':
                ++o;
                break;
            case 'u': case 'U':
                ++u;
                break;
            case ' ':
                ++space;
                break;
            case '\t':
                ++tab;
                break;
            case '\n':
                ++endline;
                break;
            default:
                ++other;
                break;
        }
    }
    cout << "a/A:\t" << a << endl;
    cout << "e/E:\t" << e << endl;
    cout << "i/I:\t" << i << endl;
    cout << "o/O:\t" << o << endl;
    cout << "u/U:\t" << u << endl;
    cout << "sapce:\t" << space << endl;
    cout << "tab:\t" << tab << endl;
    cout << "endline:\t" << endline << endl;
    cout << "ff:\t" << ff << endl;
    cout << "fi:\t" << fi << endl;
    cout << "fl:\t" << fl << endl;
    cout << "other:\t" << other << endl;
}
