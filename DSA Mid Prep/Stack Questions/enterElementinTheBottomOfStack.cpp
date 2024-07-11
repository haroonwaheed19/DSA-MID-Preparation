#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s1;
    stack<int> s2;
    s1.push(5);
    s1.push(4);
    s1.push(1);
    s1.push(7);
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    int n;
    cout << "Enter element which you want to add in the bottom : ";
    cin >> n;
    s2.push(n);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    return 0;
}