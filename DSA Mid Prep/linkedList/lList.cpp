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
    ~Node()
    {
        delete next;
        next = NULL;
    }
};

class LL
{
private:
    Node *head;
    Node *tail;

public:
    LL()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int n)
    {
        if (head == NULL)
        {
            cout << "\nInserting at Head" << endl;
            Node *temp = new Node;
            temp->data = n;
            temp->next = NULL;
            head = temp;
            tail = temp;
            cout << "\n"
                 << n << " insert successfully" << endl;
        }
        else
        {
            cout << "\nInserting at Head" << endl;
            Node *temp = new Node;
            temp->data = n;
            temp->next = NULL;
            temp->next = head;
            head = temp;
            cout << "\n"
                 << n << " insert successfully" << endl;
        }
    }
    void insertAtTail(int n)
    {
        if (head == NULL)
        {
            cout << "\nInserting at Tail" << endl;
            Node *temp = new Node;
            temp->data = n;
            temp->next = NULL;
            head = tail = temp;
            cout << "\n"
                 << n << " insert successfully" << endl;
        }
        else
        {
            cout << "\nInserting at Tail" << endl;
            Node *temp = new Node;
            temp->data = n;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
            cout << "\n"
                 << n << " insert successfully" << endl;
        }
    }
    void valueAtHead()
    {
        if (head != NULL)
        {
            cout << "Value at head is " << head->data << endl;
        }
    }
    void valueAtTail()
    {
        if (head != NULL)
        {
            cout << "Value at Tail is " << tail->data << endl;
        }
    }
    void print()
    {
        if (head != NULL)
        {
            Node *temp = head;
            cout << "Value in the linked List are : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            delete temp;
            temp = NULL;
        }
        else
        {
            cout << "Nothing to Show" << endl;
        }
    }
    /*void insertAtPosition(int pos, int n)
    {
        Node *temp = head;
        int count = 1;
        if (pos == 1)
        {
            insertAtHead(n);
        }
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        Node *node = new Node;
        node->data = n;
        node->next = temp->next;
        temp->next = node;
    }*/
    void deleteAtPosition(int pos)
    {
        if (head == NULL)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
            return;
        }
        Node *temp = head;
        int count = 1;
        while (count <= pos - 1 && temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL && temp->next == NULL)
        {
            cout << "Out of bound Range" << endl;
            return;
        }

        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        toDelete = NULL;
        cout << "Deleted Successfully" << endl;
    }
    ~LL()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
        }
    }
};
int main()
{
    LL l1;
    l1.insertAtHead(10);
    l1.valueAtHead();
    l1.insertAtHead(20);
    l1.valueAtHead();
    l1.print();
    // l1.insertAtPosition(3, 50);
    l1.insertAtTail(30);
    l1.insertAtTail(40);
    l1.valueAtTail();
    l1.print();
    l1.deleteAtPosition(1);
    l1.print();
    return 0;
}