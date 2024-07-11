#include <iostream>
#include <string>
using namespace std;
int main()
{
    // arr = 1 2 3 4 5  --> 1 2 3 10 4 5
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
    int index = 0, key = 0;
    int j = n - 1;
    n++;
    cout << "Enter the index in which you want to insert : ";
    cin >> index;
    cout << "Enter the key you want to insert : ";
    cin >> key;
    while (j >= index)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[index] = key;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";  
    }
    return 0;
}