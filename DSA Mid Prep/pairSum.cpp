#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n = 6;
    int arr[n] = {2, 4, 0, 2, 3,3};
    int num = 6;
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + arr[i + 1] == num)
        {
            check = true;
            cout << "Pair find " << arr[i] << " " << arr[i + 1] << endl;
        }
    }
    if (check == false)
    {
        cout << "Not found" << endl;
    }
    return 0;
}