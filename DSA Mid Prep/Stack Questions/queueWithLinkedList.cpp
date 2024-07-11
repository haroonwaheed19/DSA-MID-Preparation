#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        data = n;
        next = NULL;
    }
};
class Queue
{
private:
    Node *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    ~Queue()
    {
        Node *temp;
        while (front != NULL)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
    void enQueue(int n)
    {
        Node *newNode = new Node(n);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void deQueue()
    {
        if (!isEmpty())
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        else
        {
            cout << "\nEmpty" << endl;
        }
    }
    void Front()
    {
        cout << "\nFront element in the queue is : " << front->data << endl;
    }
    void display()
    {
        if (!isEmpty())
        {
            Node *temp = front;
            cout << "\nElements in the Queue are : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "\nEmpty" << endl;
        }
    }
};
int main()
{
    Queue q1;
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);
    q1.enQueue(50);
    q1.display();
    q1.Front();
    q1.deQueue();
    q1.Front();
    q1.display();
    return 0;
}