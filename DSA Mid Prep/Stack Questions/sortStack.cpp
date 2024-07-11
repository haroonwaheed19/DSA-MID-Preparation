#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s1;
    stack<int> s2;
    s1.push(9);
    s1.push(5);
    s1.push(4);
    s1.push(1);
    s1.push(7);
    if (s2.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    else
    {
        int top = s1.top();
        if (s2.top() > top)
        {
            s2.push(top);
            s1.pop();
        }
        else
        {
            s1.push(s1.top());
            s1.pop();
            s2.push(top);
        }
    }

    // printing the stacks
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    return 0;
}