#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};

class LL
{
private:
    Node *head;
    int size;

public:
    LL()
    {
        size = 0;
        head = NULL;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    void push(int n)
    {
        Node *newNode = new Node;
        newNode->data = n;
        if (head == NULL)
        {
            head = newNode;
            size++;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            size++;
        }
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node *temp = head;
        if (temp->next == NULL)
        {
            head = NULL;
            delete temp;
        }
        else
        {
            head = head->next;
            delete temp;
        }
    }

    int top()
    {
        if (head != NULL)
        {
            return head->data;
            // cout << head->data << endl;
        }
    }

    int sizeOfStack()
    {
        return size;
    }

    void display()
    {
        if (head != NULL)
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        else
        {
            cout << "Empty stack" << endl;
        }
    }
    ~LL()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main()
{
    LL l1;
    l1.display();
    l1.push(10);
    l1.push(20);
    l1.push(30);
    l1.push(40);
    cout << l1.top() << endl;
    l1.display();
    cout << endl;
    cout << l1.sizeOfStack() << endl;
    l1.pop();
    l1.display();
    return 0;
}
