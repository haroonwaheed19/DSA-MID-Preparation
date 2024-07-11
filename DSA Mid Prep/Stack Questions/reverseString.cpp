#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    stack<char> s1;
    string name = "Huzaifa";
    int i = 0;
    while (name[i] != '\0')
    {
        s1.push(name[i]);
        i++;
    }
    cout << "\nReverse of the given word is: ";
    string ans = "";
    while (!s1.empty())
    {
        char ch = s1.top();
        ans.push_back(ch);
        s1.pop();
    }
    cout << ans << endl;
    return 0;
}