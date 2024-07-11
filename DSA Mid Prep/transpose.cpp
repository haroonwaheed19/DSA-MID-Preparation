#include <iostream>
#include <string>
using namespace std;
int main()
{
    /*
    1 2 3   1 4 7
    4 5 6   2 5 8
    7 8 9   3 6 9
    */

    int n = 3;
    int arr[n][n] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int ans[n][n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}