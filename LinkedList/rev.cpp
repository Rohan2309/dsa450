/*
Reverse a linked list

*ITERATIVE WAY*
*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    { //constructor
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val) //head by ref and not by val because we have to mod ll
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head; //iterator (will traverse the ll)
    while (temp->next != NULL)
    {
        temp = temp->next;
    }               //we are at last element now
    temp->next = n; // n->next has already value NULL
}

void display(node *head) //head by value because wea re not mod ll
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//iterative way
node *reverse(node *&head) //returning new head of reversed LL
{
    node *prevptr = NULL;
    node *currentptr = head;
    node *nextptr;
    while (currentptr != NULL)
    {
        nextptr = currentptr->next; //already next pointer is increaing at the start of loop
        currentptr->next = prevptr;

        prevptr = currentptr;
        currentptr = nextptr;
    }
    return prevptr; //new head
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    node *newHead = reverse(head);
    display(newHead);

    return 0;
}