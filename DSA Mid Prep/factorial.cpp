#include <iostream>
#include <string>
using namespace std;
int main()
{
    // factorial of n to 1 and their sum with 1 loop
    int n = 5;
    int fact = 1;
    int sum = 0;
    for (int i = n; i >= 1; i--) // 5->120 4->24 3->6 2->2 1->1 120+24+6+2+1 = 153
    {
        fact = fact * i;
        if (i == 1)
        {
            sum = sum + fact;
            fact = 1;
            i = n;
            n--;
        }
    }
    cout << "Sum is : " << sum << endl;
    return 0;
}