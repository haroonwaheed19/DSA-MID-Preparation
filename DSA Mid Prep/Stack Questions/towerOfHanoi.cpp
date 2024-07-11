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
    LL s1, s2, s3;
    s1.push(3);
    s1.push(2);
    s1.push(1);
    s1.display();

    int count = 0;
    int n;

    while (true)
    {
        if (count == 0)
        {
            cout << "\nEnter the stack (2 or 3) in which you want to place the tower: ";
            cin >> n;

            if (n == 3)
            {
                s3.push(s1.top());
                cout << "Stack 3 is : ";
                s3.display();
                cout << endl;
            }
            else
            {
                s2.push(s1.top());
                cout << "Stack 2 is : ";
                s3.display();
                cout << endl;
            }

            s1.pop();
            cout << "Stack 1 is : ";
            s1.display();
            count++;
            cout << endl;
        }
        else
        {
            cout << "\nEnter the stack (1, 2, or 3) from which you want to move the tower: ";
            cin >> n;

            int destination;
            cout << "\nEnter the stack (1, 2, or 3) in which you want to place the tower: ";
            cin >> destination;

            LL *source;
            LL *dest;

            if (n == 1)
            {
                source = &s1;
            }
            else if (n == 2)
            {
                source = &s2;
            }
            else
            {
                source = &s3;
            }

            if (destination == 1)
            {
                dest = &s1;
            }
            else if (destination == 2)
            {
                dest = &s2;
            }
            else
            {
                dest = &s3;
            }

            if (!source->isEmpty() && (dest->isEmpty() || source->top() < dest->top()))
            {
                dest->push(source->top());
                source->pop();
                count++;
                cout << "Source Stack is : ";
                source->display();
                cout << endl;
                cout << "Destination Stack is : ";
                dest->display();
                cout << endl;
            }
        }

        int exitChoice;
        cout << "Press 0 to exit: ";
        cin >> exitChoice;

        if (exitChoice == 0)
        {
            break;
        }
    }

    s3.display();
    if (s3.top() == 1)
    {
        s3.pop();
        if (s3.top() == 2)
        {
            s3.pop();
        }
        if (s3.top() == 3)
        {
            s3.pop();
        }
        cout << "\nYou completed the game in " << count << " moves" << endl;
    }

    return 0;
}
