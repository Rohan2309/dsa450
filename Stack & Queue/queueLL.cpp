/*
 space is saved using LL for queue
 we dont have to define n as in array
*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    node *front;
    node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(int x)
    {
        node *n = new node(x);
        if (front == NULL) //if queue empty
        {
            back = front = n;
            return;
        }

        back->next = n; //next  node of back  will be n
        back = n;       //new back will be n
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        node *todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "No element in queue" << endl;
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
        {

            return true;
        }
        return false;
    }
};

int main()
{

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.empty() << endl;

    return 0;
}