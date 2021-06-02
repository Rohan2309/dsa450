/*
Implementation of stack
LIFO
push - insert
pop - remove top element
top - return top element
empty - check empty or not


array
top = -1   (no value in stack)
push (top++) and value got inserted
if top value is equal to last index we have to make a new array of bigger size
pop (top--) and value got removed
*/

#include <bits/stdc++.h>
using namespace std;

#define n 100

class Stack
{
    int *arr; //dynamically making array
    int top;  //will take care of top element of array

public:
    Stack() //constructor
    {
        arr = new int[n]; //allocating memory of array
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }

    int Top() //member function
    {
        if (top == -1) //data member
        {
            cout << "No element in stack" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1; //will return true if stack is empty
    }
};

int main()
{
    Stack st; //create stack class with name st
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top() << endl; //3 is top
    st.pop();
    cout << st.Top() << endl; //2 is top
    st.pop();
    st.pop();
    st.pop();                   //no element to pop
    cout << st.empty() << endl; //yes
    return 0;
}