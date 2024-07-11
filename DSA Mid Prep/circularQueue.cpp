#include <iostream>
#include <string>
using namespace std;
class cricularQueue
{
private:
    int qFront, rear, size;
    int *arr;

public:
    cricularQueue(int n)
    {
        size = n;
        qFront = -1;
        rear = -1;
        arr = new int[size];
    }

    bool isFull()
    {
        if ((qFront == 0 && rear == size - 1) || (qFront == rear + 1))
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (qFront == -1)
        {
            return true;
        }
        return false;
    }

    void enQueue(int n)
    {
        if (!isFull())
        {
            if (qFront == -1)
            {
                qFront++;
                rear = (rear + 1) % size;
                arr[rear] = n;
            }
            else
            {
                rear = (rear + 1) % size;
                arr[rear] = n;
            }
        }
        else
        {
            cout << "Queue OverFlow" << endl;
        }
    }

    void deQueue()
    {
        if (!isEmpty())
        {
            cout << "This element is going to deleted " << arr[qFront] << endl;
            qFront = (qFront + 1) % size;
        }
        else
        {
            cout << "Underflow";
        }
    }

    void peek()
    {
        if (!isEmpty())
        {
            cout << "\nThe peek element is : " << arr[qFront] << endl;
        }
        else
        {
            cout << "Queue UnderFlow" << endl;
        }
    }
    /*void display()
    {
        if (!isEmpty())
        {
            cout << "\nThe element in the stack is ";
            int i = qFront;
            for (int j = i; j < size; j++)
            {
                cout << arr[j] << " ";
                i = (i + 1) % size;
            }
            cout << endl;
        }
        else
        {
            cout << "Queue UnderFlow" << endl;
        }
    }*/
    void display()
    {
        if (!isEmpty())
        {
            cout << "\nThe element in the stack is ";
            int i = qFront;
            if (qFront <= rear)
            {
                for (int j = i; j <= rear; j++)
                {
                    cout << arr[j] << " ";
                }
            }
            else
            {
                for (int j = i; j < size; j++)
                {
                    cout << arr[j] << " ";
                }
                for (int j = 0; j <= rear; j++)
                {
                    cout << arr[j] << " ";
                }
            }
            cout << endl;
        }
        else
        {
            cout << "Queue UnderFlow" << endl;
        }
    }

    ~cricularQueue()
    {
        delete[] arr;
        arr = NULL;
    }
};

int main()
{
    cricularQueue q1(5);
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(25);
    q1.enQueue(30);
    q1.enQueue(35);
    q1.display();
    q1.enQueue(40);
    q1.peek();
    q1.deQueue();
    q1.enQueue(40);
    q1.peek();
    q1.display();
    return 0;
}