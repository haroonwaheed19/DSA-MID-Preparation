#include <iostream>
#include <string>
using namespace std;
class Hanaoi
{
private:
    int top;
    int size;
    int *stack;

public:
    Hanaoi(int s)
    {
        top = -1;
        size = s;
        stack = new int[size];
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        return false;
    }
    void push(int n)
    {
        if (!isFull())
        {
            top++;
            stack[top] = n;
        }
        else
        {
            cout << "Tower OverFlow" << endl;
        }
    }
    void pop()
    {
        if (!isEmpty())
        {
            top--;
        }
        else
        {
            cout << "Tower is Empty" << endl;
        }
    }
    int getTop()
    {
        return stack[top];
    }
    void display()
    {
        if (!isEmpty())
        {
            for (int i = top; i >= 0; i--)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Tower is Empty" << endl;
        }
    }
    ~Hanaoi()
    {
        delete stack;
    }
};

void displayTower(Hanaoi &h1, Hanaoi &h2, Hanaoi &h3)
{
    cout << "\n\t\tTower 1 : ";
    h1.display();
    cout << "\n\t\tTower 2 : ";
    h2.display();
    cout << "\n\t\tTower 3 : ";
    h3.display();
}

void playGame(Hanaoi &h1, Hanaoi &h2, Hanaoi &h3, int &count)
{
    int from, to;
    while (!h1.isEmpty() || !h2.isEmpty())
    {
        cout << "\nFrom which Tower you want to move the Disc(1, 2 or 3) : ";
        cin >> from;
        cout << "\nIn which Tower you want to Place the Disc(1, 2 or 3) : ";
        cin >> to;
        if (from == 1 && to == 2)
        {
            if (h1.isEmpty())
            {
                cout << "Cannot move Tower is empty" << endl;
            }
            else
            {
                if (!h2.isEmpty())
                {
                    if (h2.getTop() > h1.getTop())
                    {
                        h2.push(h1.getTop());
                        h1.pop();
                        count++;
                        displayTower(h1, h2, h3);
                    }
                    else
                    {
                        cout << "\nCannot place the disc because the disc is greater than then already exist disc at top" << endl;
                    }
                }
                else
                {
                    h2.push(h1.getTop());
                    h1.pop();
                    count++;
                    displayTower(h1, h2, h3);
                }
            }
        }
        else if (from == 1 && to == 3)
        {
            if (h1.isEmpty())
            {
                cout << "Cannot move Tower is empty" << endl;
            }
            else
            {
                if (!h3.isEmpty())
                {
                    if (h3.getTop() > h1.getTop())
                    {
                        h3.push(h1.getTop());
                        h1.pop();
                        count++;
                        displayTower(h1, h2, h3);
                    }
                    else
                    {
                        cout << "\nCannot place the disc because the disc is greater than then already exist disc at top" << endl;
                    }
                }
                else
                {
                    h3.push(h1.getTop());
                    h1.pop();
                    count++;
                    displayTower(h1, h2, h3);
                }
            }
        }
        else if (from == 2 && to == 1)
        {
            if (h2.isEmpty())
            {
                cout << "Cannot move Tower is empty" << endl;
            }
            else
            {
                if (!h1.isEmpty())
                {
                    if (h1.getTop() > h2.getTop())
                    {
                        h1.push(h2.getTop());
                        h2.pop();
                        count++;
                        displayTower(h1, h2, h3);
                    }
                    else
                    {
                        cout << "\nCannot place the disc because the disc is greater than then already exist disc at top" << endl;
                    }
                }
                else
                {
                    h1.push(h2.getTop());
                    h2.pop();
                    count++;
                    displayTower(h1, h2, h3);
                }
            }
        }
        else if (from == 2 && to == 3)
        {
            if (h2.isEmpty())
            {
                cout << "Cannot move Tower is empty" << endl;
            }
            else
            {
                if (!h3.isEmpty())
                {
                    if (h3.getTop() > h2.getTop())
                    {
                        h3.push(h2.getTop());
                        h2.pop();
                        count++;
                        displayTower(h1, h2, h3);
                    }
                    else
                    {
                        cout << "\nCannot place the disc because the disc is greater than then already exist disc at top" << endl;
                    }
                }
                else
                {
                    h3.push(h2.getTop());
                    h2.pop();
                    count++;
                    displayTower(h1, h2, h3);
                }
            }
        }
        else if (from == 3 && to == 1)
        {
            if (h3.isEmpty())
            {
                cout << "Cannot move Tower is empty" << endl;
            }
            else
            {
                if (!h1.isEmpty())
                {
                    if (h1.getTop() > h3.getTop())
                    {
                        h1.push(h3.getTop());
                        h3.pop();
                        count++;
                        displayTower(h1, h2, h3);
                    }
                    else
                    {
                        cout << "\nCannot place the disc because the disc is greater than then already exist disc at top" << endl;
                    }
                }
                else
                {
                    h1.push(h3.getTop());
                    h3.pop();
                    count++;
                    displayTower(h1, h2, h3);
                }
            }
        }
        else if (from == 3 && to == 2)
        {
            if (h3.isEmpty())
            {
                cout << "Cannot move Tower is empty" << endl;
            }
            else
            {
                if (!h2.isEmpty())
                {
                    if (h2.getTop() > h3.getTop())
                    {
                        h2.push(h3.getTop());
                        h3.pop();
                        count++;
                        displayTower(h1, h2, h3);
                    }
                    else
                    {
                        cout << "\nCannot place the disc because the disc is greater than then already exist disc at top" << endl;
                    }
                }
                else
                {
                    h2.push(h3.getTop());
                    h3.pop();
                    count++;
                    displayTower(h1, h2, h3);
                }
            }
        }
        else
        {
            cout << "\nInvalid Choice" << endl;
        }
    }
    cout << "                ------------------------------------" << endl;
    cout << "\n\t\tCongratulation You Complete the game in : " << count << " Moves" << endl;
    cout << "                ------------------------------------" << endl;
    cout << "\n\n";
}
int main()
{
    int size = 3;
    int count = 0;
    Hanaoi h1(size), h2(size), h3(size);
    h1.push(3);
    h1.push(2);
    h1.push(1);
    cout << "            ----------------------------" << endl;
    cout << "             Welcome to Tower of Hanoi" << endl;
    cout << "            ----------------------------" << endl;
    cout << "\nTo play this game you have to move all the discs into Tower 3.But you cannot place a larger disc onto a smaller disk." << endl;
    cout << "\n\n";
    displayTower(h1, h2, h3);
    playGame(h1, h2, h3, count);
    return 0;
}