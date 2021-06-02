/*
Implementation of queue
FIFO property

pointers 
front -> element removed from
back -> insert

queue

  z       y
front   back

enqueue(x) -> insert element at back

  z     y    x
front       back

dequeue -> remove from front

  y       x
front   back

peek() -> tells value at front
empty() -> queue empty or not


Array implementation
front and back both at -1 at first
to insert a value (back++)
front will also come // for first time as it was in -1

to remove (front++)
peek returns front value

empty when front = back(1 element is there)
when front > back then emnpty
or else front =-1
*/

#include <bits/stdc++.h>
using namespace std;

#define n 20

class Queue
{
    int *arr; //dynamically making array
    int front, back;

public:
    Queue() //constructor
    {
        arr = new int[n]; //allocating memory of array
        front = -1;
        back = -1;
    }

    void enqueue(int x)
    {
        if (back == n - 1)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        back++;
        arr[back] = x;

        if (front == -1) //for first element only
        {
            front++;
        }
    }

    void dequeue()
    {
        if (front == -1 or front > back)
        {
            cout << "No elements in queue" << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 or front > back)
        {
            cout << "No elements in queue" << endl;
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if (front == -1 or front > back)
        {
            cout << "No elements in queue" << endl;
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q; //object of class queue
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