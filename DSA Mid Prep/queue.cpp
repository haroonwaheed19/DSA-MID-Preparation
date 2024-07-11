#include <iostream>
#include <string>
using namespace std;
class Queue
{
private:
    int qFront, rear, size;
    int *arr;

public:
    Queue(int n)
    {
        size = n;
        qFront = -1;
        rear = -1;
        arr = new int[size];
    }

    bool isFull()
    {
        if (rear == size - 1)
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
                rear++;
                arr[rear] = n;
            }
            else
            {
                rear++;
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
            qFront++;
        }
        else
        {
            cout << "Underflow";
        }
    }

    void displayQueue()
    {
        if (!isEmpty())
        {
            cout << "\nThe element in the Queue is : ";
            for (int i = qFront; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            cout << "Queue UnderFlow" << endl;
        }
    }

    void peek()
    {
        if (!isEmpty())
        {
            cout << "The peek element is : " << arr[qFront] << endl;
        }
        else
        {
            cout << "Queue UnderFlow" << endl;
        }
    }
    ~Queue()
    {
        delete[] arr;
        arr = NULL;
    }
};
int main()
{
    Queue q1(5);
    q1.peek();
    q1.displayQueue();
    q1.enQueue(10);
    q1.enQueue(15);
    q1.peek();
    return 0;
}