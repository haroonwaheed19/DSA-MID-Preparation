#include <iostream>
#include <string>
using namespace std;
class pQueue
{
private:
    int row;
    int col;
    int **queue;
    int *front, *rear;

public:
    pQueue(int r, int c)
    {
        row = r;
        col = c;
        queue = new int *[row];
        front = new int[row];
        rear = new int[row];

        for (int i = 0; i < row; ++i)
        {
            queue[i] = new int[col];
            front[i] = -1; // Initialize individual elements to -1
            rear[i] = -1;  // Initialize individual elements to -1
        }
    }

    ~pQueue()
    {
        for (int i = 0; i < row; ++i)
        {
            delete[] queue[i];
        }
        delete[] queue;
        delete[] front;
        delete[] rear;
    }
    bool isFull(int p)
    {
        if (rear[p - 1] >= col - 1)
        {
            return true;
        }
        return false;
    }
    bool isEmpty(int p)
    {
        if (front[p - 1] == -1)
        {
            return true;
        }
        return false;
    }

    void Front(int p)
    {
        if (!isEmpty(p))
        {
            cout << "\nThe front element of priority " << p << " is " << queue[p - 1][front[p - 1]] << endl;
        }
        else
        {
            cout << "\nNothing to show front element for this priority : " << p << endl;
        }
    }

    void push(int p, int n)
    {
        if (!isFull(p))
        {
            if (front[p - 1] == -1)
            {
                front[p - 1] = rear[p - 1] = 0;
                queue[p - 1][rear[p - 1]] = n;
                cout << "\nValue " << n << " is inserted successfully at priority : " << p << endl;
            }
            else
            {
                rear[p - 1]++;
                queue[p - 1][rear[p - 1]] = n;
                cout << "\nValue " << n << " is inserted successfully at priority : " << p << endl;
            }
        }
        else
        {
            cout << "\nPriority Queue Overflow for " << p << " priority so cannot assign value " << n << " to this priority" << endl;
        }
    }
    void pop(int p)
    {
        if (!isEmpty(p))
        {
            cout << "\nValue " << queue[p - 1][front[p - 1]] << " is popped out successfully at priority : " << p << endl;
            if (front[p - 1] == rear[p - 1])
            {
                front[p - 1] = rear[p - 1] = -1;
            }
            else
            {
                front[p - 1]++;
            }
        }
        else
        {
            cout << "\nNothing to delete for this priority " << p << " " << endl;
        }
    }

    void display()
    {
        for (int i = 0; i < row; i++)
        {
            cout << "\nPriority " << i + 1 << " Queue "
                 << ": ";
            for (int j = 0; j <= rear[i]; j++)
            {
                cout << queue[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    pQueue p1(3, 3);
    p1.push(1, 10);
    p1.push(1, 20);
    p1.push(1, 30);
    p1.Front(1);
    p1.pop(1);
    p1.Front(1);
    p1.push(1, 40);
    p1.push(2, 40);
    p1.pop(2);
    p1.pop(2);
    p1.Front(2);
    p1.push(3, 50);
    p1.display();
    return 0;
}