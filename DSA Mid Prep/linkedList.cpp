#include <iostream>
#include <string>
using namespace std;
struct node
{
    int data;
    node *nextNode;
};

class linkedList
{
private:
    node *head;
    node *tail;

public:
    linkedList()
    {
        head = NULL;
        tail = NULL;
    }
    ~linkedList()
    {
        cout << "\nDestructor called" << endl;
        node *temp = head;
        while (temp != NULL)
        {
            temp = head->nextNode;
            delete temp;
        }
        delete temp;
        temp = NULL;
    }

    void append(int n)
    {
        if (head == NULL)
        {
            cout << "Insert at head" << endl;
            node *newNode = new node;
            newNode->data = n;
            newNode->nextNode = NULL;
            head = newNode;
            tail = newNode;
            cout << n << " Insert Succesfully" << endl;
        }
        else
        {
            cout << "insert at Tail" << endl;
            node *newNode = new node;
            newNode->data = n;
            newNode->nextNode = NULL;
            tail->nextNode = newNode;
            tail = newNode;
            cout << n << " Insert Succesfully" << endl;
        }
    }
    void print()
    {
        node *temp = head;
        cout << "Element in the linked list are : ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->nextNode;
        }
    }
};

int main()
{
    linkedList l1;
    l1.append(10);
    l1.append(20);
    l1.append(30);
    l1.print();

    return 0;
}