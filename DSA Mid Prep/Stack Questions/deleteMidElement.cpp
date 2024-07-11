#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    int n = s1.size();
    stack<int> s2;
    int count = 0;
    while (count != n / 2)
    {
        s2.push(s1.top());
        s1.pop();
        count++;
    }
    s1.pop();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    cout << "The modified stack is: ";
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    return 0;
}