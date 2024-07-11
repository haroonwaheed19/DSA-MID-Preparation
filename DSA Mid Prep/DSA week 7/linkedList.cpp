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
        next = NULL;
        delete next;
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
        head = tail = NULL;
    }

    // prepend
    void insertionAtHead(int n)
    {
        Node *newNode = new Node;
        newNode->data = n;

        // if no head exists
        if (head == NULL)
        {
            cout << "\nInsertion at head" << endl;
            head = newNode;
            tail = newNode;
            cout << "\n"
                 << n << " insert Successfully" << endl;
        }
        else
        {
            cout << "\nInsertion at head" << endl;
            newNode->next = head;
            head = newNode;
            cout << "\n"
                 << n << " insert Successfully" << endl;
        }
    }

    void valueAtHead()
    {
        if (head != NULL)
        {
            cout << "\nValue at head is : " << head->data << endl;
        }
        else
        {
            cout << "Empty LinkedList" << endl;
        }
    }

    // append
    void insertionAtTail(int n)
    {
        Node *newNode = new Node;
        newNode->data = n;
        newNode->next = NULL;

        // if no head exist
        if (head == NULL)
        {
            cout << "\nInsertion at Tail" << endl;
            head = newNode;
            tail = newNode;
            cout << "\n"
                 << n << " insert Successfully" << endl;
        }
        else
        {
            cout << "\nInsertion at Tail" << endl;
            tail->next = newNode;
            tail = newNode;
            cout << "\n"
                 << n << " insert Successfully" << endl;
        }
    }
    void valueAtTail()
    {
        if (head != NULL)
        {
            cout << "\nValue at Tail is : " << tail->data << endl;
        }
        else
        {
            cout << "Empty linkedList" << endl;
        }
    }

    // print LinkedList
    void displayLinkedList()
    {
        if (head != NULL)
        {
            cout << "The values in the linked list are: ";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            // cout << temp->data;
            cout << endl;
        }
        else
        {
            cout << "linked List is Empty" << endl;
        }
    }
    void deleteAtHead()
    {
        if (head != NULL)
        {
            Node *temp1 = head;
            head = head->next;
            temp1 = NULL;
            delete temp1;
            cout << "\nDeleted Successfully" << endl;
        }
        else
        {
            cout << "\nEmpty LinkedList" << endl;
        }
    }
    void deleteAtMid()
    {
        Node *fast, *slow, *pre;
        fast = slow = head;
        pre = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = slow->next;
        delete slow;
    }

    void deleteAtTail()
    {
        if (head != NULL)
        {
            Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            tail = temp;
            temp = temp->next;
            tail->next = NULL;
            delete temp;
        }
        else
        {
            cout << "Empty LinkedList" << endl;
        }
    }

    void deleteAtPosition(int pos)
    {
        int count = 1;
        if (pos == 1)
        {
            count++;
            deleteAtHead();
        }

        Node *temp = head;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        cout << "Element at top " << temp->data << endl;
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    ~LL()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            temp = NULL;
            delete temp;
        }
    }
};
int main()
{
    LL l1;
    l1.insertionAtHead(10);
    l1.valueAtHead();
    l1.insertionAtHead(20);
    l1.insertionAtHead(30);
    // l1.valueAtHead();
    // l1.deleteAtHead();
    l1.displayLinkedList();
    // l1.valueAtHead();
    l1.insertionAtTail(40);
    l1.valueAtTail();
    l1.insertionAtTail(50);
    l1.insertionAtTail(60);
    l1.valueAtTail();
    // l1.deleteAtHead();
    // l1.del();
    l1.displayLinkedList();
    l1.deleteAtPosition(4);
    l1.displayLinkedList();
    // l1.deleteAtTail();
    // l1.displayLinkedList();
    // l1.deleteAtTail();
    // l1.displayLinkedList();
    // l1.deleteAtMid();
    // l1.displayLinkedList();
    // l1.deleteAtMid();
    // l1.displayLinkedList();
    // l1.deleteAtMid();
    // l1.displayLinkedList();
    // l1.deleteAtMid();
    // l1.displayLinkedList();
    return 0;
}