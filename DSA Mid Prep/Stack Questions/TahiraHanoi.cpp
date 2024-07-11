#include <iostream>
using namespace std;
class Hanoi
{
private:
    int top;
    int size;
    int *stackArray;

public:
    Hanoi()
    {
    }
    friend void towerOfHanoi(Hanoi &obj1, Hanoi &obj2, Hanoi &obj3);
    Hanoi(int s)
    {
        size = s;
        top = -1;
        stackArray = new int[size];
    }
    bool isEmpty()
    {
        return (top == -1) ? true : false;
    }
    bool isFullStack()
    {
        return (top == size - 1) ? true : false;
    }
    void push(int value)
    {
        if (!isFullStack())
        {
            top++;
            stackArray[top] = value;
        }
        else
        {
            cout << "Tower is Full. Can't insert new number" << endl;
        }
    }
    int pop()
    {
        if (!isEmpty())
        {
            return stackArray[top--];
        }
        else
        {
            cout << "Tower is empty" << endl;
        }
    }
    int topValue()
    {
        if (!isEmpty())
        {
            // cout << stackArray[top] << endl;
            return stackArray[top];
        }
    }
    void display()
    {
        if (!isEmpty())
        {
            for (int i = top; i >= 0; i--)
            {
                cout << stackArray[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "This tower is empty" << endl;
        }
    }
};
void display1(Hanoi &obj1, Hanoi &obj2, Hanoi &obj3)
{
    cout<<"Tower 1: ";
    obj1.display();
    cout<<"Tower 2: ";
    obj2.display();
    cout<<"Tower 3: ";
    obj3.display();
}
void towerOfHanoi(Hanoi &obj1, Hanoi &obj2, Hanoi &obj3)
{
    int from, to;
    while (obj3.top != 2)
    {
        cout << "Enter the number of tower from where you want to shift the top-number= ";
        cin >> from;
        cout << "Enter the number of tower to where you want to shift that number= ";
        cin >> to;
        if (from == 1 && to == 2)
        {
            if (!obj2.isEmpty())
            {

                if (obj2.topValue() > obj1.topValue())
                {
                    obj2.push(obj1.pop());
                    display1(obj1, obj2, obj3);
                }
                else
                {
                    cout << "\nCan't shift value as it is greater than the already placed value\n" << endl;
                }
            }
            else
            {
                obj2.push(obj1.pop());
                display1(obj1, obj2, obj3);
            }
        }

        else if (from == 1 && to == 3)
        {
            if (!obj3.isEmpty())
            {

                if (obj3.topValue() > obj1.topValue())
                {
                    obj3.push(obj1.pop());
                    display1(obj1, obj2, obj3);
                }
                else
                {
                    cout << "\nCan't shift value as it is greater than the already placed value\n" << endl;
                }
            }
            else
            {
                obj3.push(obj1.pop());
                display1(obj1, obj2, obj3);
            }
        }
        else if(from==2 && to==1)
        {
            if (!obj1.isEmpty())
            {

                if (obj1.topValue() > obj2.topValue())
                {
                    obj1.push(obj2.pop());
                    display1(obj1, obj2, obj3);
                }
                else
                {
                    cout << "\nCan't shift value as it is greater than the already placed value\n" << endl;
                }
            }
            else
            {
                obj1.push(obj2.pop());
                display1(obj1, obj2, obj3);
            }
        }
        else if(from==3 && to==1)
        {
            if (!obj1.isEmpty())
            {

                if (obj1.topValue() > obj3.topValue())
                {
                    obj1.push(obj3.pop());
                    display1(obj1, obj2, obj3);
                }
                else
                {
                    cout << "\nCan't shift value as it is greater than the already placed value\n" << endl;
                }
            }
            else
            {
                obj1.push(obj3.pop());
                display1(obj1, obj2, obj3);
            }
        }
        else if(from==2 && to==3)
        {
            if(!obj3.isEmpty())
            {
                if(obj3.topValue()>obj2.topValue())
                {
                    obj3.push(obj2.pop());
                    display1(obj1, obj2, obj3);
                }
                else
                {
                    cout << "\nCan't shift value as it is greater than the already placed value\n" << endl;
                }
            }
            else
            {
                obj3.push(obj2.pop());
                display1(obj1, obj2, obj3);
            }
        }
        else if(from==3 && to==2)
        {
            if(!obj2.isEmpty())
            {
                if(obj2.topValue()>obj3.topValue())
                {
                    obj2.push(obj3.pop());
                    display1(obj1, obj2, obj3);
                }
                else
                {
                    cout << "\nCan't shift value as it is greater than the already placed value\n" << endl;
                }
            }
            else
            {
                obj2.push(obj3.pop());
                display1(obj1, obj2, obj3);
            }
        }
        else
        {
            cout<<"Wrong choice"<<endl;
        }
    }
}
int main()
{
    int size = 3;
    Hanoi obj1(size), obj2(size), obj3(size);
    obj1.push(6);
    obj1.push(3);
    obj1.push(2);
    cout << "            ----------------------------" << endl;
    cout << "             Welcome to Tower of Hanoi" << endl;
    cout << "            ----------------------------" << endl;
    cout << "\nObject of the game is to move all the numbers over to Tower 3.But you cannot place a larger number onto a smaller number." << endl;
    cout << "\n";
    cout << "|\t\t | \t\t |" << endl;
    cout << "|\t\t | \t\t |" << endl;
    cout << "|\t\t | \t\t |" << endl;
    cout << "|\t\t | \t\t |" << endl;
    cout << "|\t\t | \t\t |" << endl;
    cout << "2\t\t | \t\t |" << endl;
    cout << "3\t\t | \t\t |" << endl;
    cout << "6\t\t | \t\t |" << endl;
    cout << "\n\n";
    towerOfHanoi(obj1, obj2, obj3);
}