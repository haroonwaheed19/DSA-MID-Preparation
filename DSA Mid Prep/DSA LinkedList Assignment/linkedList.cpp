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

class linkedList
{
private:
    Node *head, *tail;

public:
    linkedList()
    {
        head = tail = NULL;
    }
    ~linkedList()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // prepend function
    void insertAtHead(int n)
    {
        Node *newNode = new Node;
        newNode->data = n;
        if (head == NULL)
        {
            cout << "Insertion At Head" << endl;
            head = newNode;
            tail = newNode;
            cout << n << " is insert Successfully" << endl;
        }
        else
        {
            cout << "Insertion At Head" << endl;
            newNode->next = head;
            head = newNode;
            cout << n << " is insert Successfully" << endl;
        }
    }

    // append function
    void insertAtTail(int n)
    {
        Node *newNode = new Node;
        newNode->data = n;
        if (head == NULL)
        {
            cout << "Insertion At Tail" << endl;
            head = tail = newNode;
            cout << n << " is insert Successfully" << endl;
        }
        else
        {
            cout << "Insertion At Tail" << endl;
            tail->next = newNode;
            tail = newNode;
            cout << n << " is insert Successfully" << endl;
        }
    }
    void display()
    {
        if (head != NULL && tail != NULL)
        {
            Node *temp = head;
            cout << "\nValue in the linked List are : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            delete temp;
        }
        else
        {
            cout << "\nCannot print Empty Linked List" << endl;
        }
    }
    void deleteAtHead()
    {
        if (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "\nDeleted successfully at head" << endl;
            if (head == NULL)
            {
                tail = NULL;
            }
        }
        else
        {
            cout << "\nCannot delete Empty linkedList" << endl;
        }
    }
    void deleteAtTail()
    {
        if (head != NULL && tail != NULL)
        {
            Node *pre = NULL, *curr = head;

            while (curr->next != NULL)
            {
                pre = curr;
                curr = curr->next;
            }

            if (pre == NULL)
            {
                // Only one element in the list
                delete head;
                head = tail = NULL;
                cout << "\nDeleted successfully at Tail" << endl;
            }
            else
            {
                pre->next = NULL;
                tail = pre;
                delete curr;
                cout << "\nDeleted successfully at Tail" << endl;
            }
        }
        else
        {
            cout << "\nCannot delete Empty LinkedList" << endl;
        }
    }
    // Delete a node at the specified position
    void deleteAtPosition(int pos)
    {
        if (head != NULL)
        {
            if (pos <= 0)
            {
                cout << "\nInvalid Position" << endl;
            }
            else if (pos == 1)
            {
                deleteAtHead();
            }
            else
            {
                int count = 1;
                Node *temp = head;
                Node *pre = nullptr;

                while (count < pos && temp != NULL)
                {
                    pre = temp;
                    temp = temp->next;
                    count++;
                }

                if (temp != NULL)
                {
                    pre->next = temp->next;
                    if (pre->next == NULL)
                    {
                        tail = pre;
                    }

                    delete temp;
                    cout << "\nDeleted successfully at position " << pos << endl;
                }
                else
                {
                    cout << "\nPosition out of bounds" << endl;
                }
            }
        }
        else
        {
            cout << "\nCannot delete from an empty LinkedList" << endl;
        }
    }
    void deleteAtMid()
    {
        if (head != NULL)
        {
            Node *fast = head;
            Node *slow = head;
            Node *pre = NULL;

            while (fast != NULL && fast->next != NULL)
            {
                fast = fast->next->next;
                pre = slow;
                slow = slow->next;
            }

            if (pre != NULL)
            {
                pre->next = slow->next;
            }
            else
            {
                // This is the case when there is only one element in the list
                head = slow->next;
            }

            delete slow;
            cout << "\nDeleted successfully at mid" << endl;
        }
        else
        {
            cout << "\nNothing to delete in the linkedList" << endl;
        }
    }
    void searchInLinkedList(int num)
    {
        if (head != NULL)
        {
            bool found = false;
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp->data == num)
                {
                    cout << "\n"
                         << num << " is present in the linked List" << endl;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }
            if (found == false)
            {
                cout << "\nThis element " << num << " is not in the linked list " << endl;
            }
        }
        else
        {
            cout << "Empty Linked List" << endl;
        }
    }
    void sortLinkedList()
    {
        if (head != NULL)
        {
            Node *temp1 = head;

            while (temp1 != NULL)
            {
                Node *temp2 = temp1->next;

                while (temp2 != NULL)
                {
                    if (temp1->data > temp2->data)
                    {
                        int num = temp1->data;
                        temp1->data = temp2->data;
                        temp2->data = num;
                    }
                    temp2 = temp2->next;
                }

                temp1 = temp1->next;
            }
        }
        else
        {
            cout << "Empty linked List" << endl;
        }
    }
};
int main()
{
    linkedList l1;
    // int choice = 0;
    // do
    // {
    //     cout << "Press 1 to insert at Head" << endl;
    //     cout << "Press 2 to insert at Tail" << endl;
    //     cout << "Press 3 to delete at Head" << endl;
    //     cout << "Press 4 to delete at Tail" << endl;
    //     cout << "Press 5 to delete at Mid" << endl;
    //     cout << "Press 6 to delete at specific position" << endl;
    //     cout << "Press 7 to display the list" << endl;
    //     cout << "Press 8 to exit" << endl;
    //     cin >> choice;
    //     if (choice == 1)
    //     {
    //         cout << "Enter the element you want to insert : ";
    //         int n;
    //         cin >> n;
    //         l1.insertAtHead(n);
    //     }
    //     else if (choice == 2)
    //     {
    //         cout << "Enter the element you want to insert : ";
    //         int n;
    //         cin >> n;
    //         l1.insertAtTail(n);
    //     }
    //     else if (choice == 3)
    //     {
    //         l1.deleteAtHead();
    //     }
    //     else if (choice == 4)
    //     {
    //         l1.deleteAtTail();
    //     }
    //     else if (choice == 5)
    //     {
    //         l1.deleteAtMid();
    //     }
    //     else if (choice == 6)
    //     {
    //         cout << "Enter the position from 1 to higehr to delete : ";
    //         int pos;
    //         cin >> pos;
    //         l1.deleteAtPosition(pos);
    //     }
    //     else if (choice == 7)
    //     {
    //         l1.display();
    //     }
    //     else if (choice == 8)
    //     {
    //         cout << "Exiting!" << endl;
    //         break;
    //     }
    //     else
    //     {
    //         cout << "Invalid Choice" << endl;
    //         break;
    //     }
    // } while (choice != 8);
    l1.insertAtHead(10);
    l1.insertAtHead(5);
    l1.insertAtTail(20);
    l1.insertAtTail(50);
    l1.insertAtTail(30);
    l1.insertAtTail(40);
    l1.insertAtTail(25);
    l1.deleteAtMid();
    // l1.deleteAtPosition(7);
    l1.display();
    l1.searchInLinkedList(100);
    l1.sortLinkedList();
    l1.display();
    return 0;
}