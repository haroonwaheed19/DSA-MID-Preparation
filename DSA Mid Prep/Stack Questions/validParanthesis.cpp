#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    stack<char> s;
    string exp = "({[([{}])]})";
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if ((top == '{' && ch == '}') || (top == '[' && ch == ']') || (top == '(' && ch == ')'))
                {
                    s.pop();
                }
                else
                {
                    cout << "InValid Paranthesis" << endl;
                    break;
                }
            }
            else
            {
                cout << "Empty stacks" << endl;
                break;
            }
        }
    }
    if (s.empty())
    {
        cout << "Valid Paranthesis" << endl;
    }
    else
    {
        cout << "Invalid Paranthesis" << endl;
    }
    return 0;
}