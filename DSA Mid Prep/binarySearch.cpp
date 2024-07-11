#include <iostream>
#include <string>
using namespace std;
void binarySearch(int *arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + ((e - s) / 2);
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            cout << "Element found at index: " << mid << endl;
            break;
        }

        if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + ((e - s) / 2);
    }
}
int main()
{
    int n = 6;
    int arr[n] = {10, 33, 53, 85, 116, 198};
    int key;
    cout << "Enter the element you want to find : ";
    cin >> key;
    binarySearch(arr, n, key);
    return 0;
}