#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    int size, top;
    int *arr;

public:
    Stack(int n)
    {
        size = n;
        top = -1;
        arr = new int[size];
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    void push(int num)
    {
        if (!isFull())
        {
            top++;
            arr[top] = num;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            // cout << "This element is going to pop-out " << arr[top] << endl;
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek()
    {
        // cout << "\nThe peek element in the stack is : " << arr[top] << endl;
        return arr[top];
    }

    void displayStack()
    {
        if (!isEmpty())
        {
            cout << "\nThe element in the stack are : ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            cout << "The stack is Empty" << endl;
        }
    }
    ~Stack()
    {
        delete[] arr;
        arr = NULL;
    }
};
void sortStack(Stack &temp, Stack &s1)
{
    while (!s1.isEmpty())
    {
        int x = s1.peek();
        s1.pop();

        while (!temp.isEmpty() && temp.peek() > x)
        {
            s1.push(temp.peek());
            temp.pop();
        }
        temp.push(x);
    }

    while (!temp.isEmpty())
    {
        s1.push(temp.peek());
        temp.pop();
    }
}

int main()
{
    int n = 5;
    Stack s1(n);
    Stack temp(n);
    s1.displayStack();
    s1.push(10);
    s1.push(15);
    s1.push(5);
    s1.push(25);
    s1.push(2);
    s1.displayStack();
    sortStack(temp, s1);
    s1.displayStack();
    return 0;
}