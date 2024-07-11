#include <iostream>
#include <string>
#include <stack>
using namespace std;

void displayStack(stack<int> &s)
{
    if (!s.empty())
    {
        stack<int> s1;
        for (int i = s.size(); i >= 0; i--)
        {
            cout << s.top() << " ";
            s1.push(s.top());
            s.pop();
        }
        while (!s1.empty())
        {
            s.push(s1.top());
            s1.pop();
        }
    }
}

int main()
{
    stack<int> s1, s2, s3;
    s1.push(3);
    s1.push(2);
    s1.push(1);
    displayStack(s1);
    s3.push(s1.top());
    s1.pop();
    s2.push(s1.top());
    s1.pop();
    s2.push(s3.top());
    s3.pop();
    s3.push(s1.top());
    s1.top();
    s1.push(s2.top());
    s2.pop();
    s3.push(s2.top());
    s2.top();
    s3.push(s1.top());
    s1.pop();
    displayStack(s3);

    return 0;
}