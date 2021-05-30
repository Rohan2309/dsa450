/*
Rotate Doubly linked list by N nodes

Given a doubly linked list, rotate the linked list counter-clockwise by N nodes. 
Here N is a given positive integer and is smaller than the count of nodes in linked list. 

input 1,2,3,4,5
output 3,4,5,1,2
*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev; //for dll

    node(int val)
    { //constructor
        data = val;
        next = NULL;
        prev = NULL; //for dll
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL) //if head is there then only we can point to prev
    {
        head->prev = n; //for dll
    }
    head = n;
}

void insertAtTail(node *&head, int val) //head by ref and not by val because we have to mod ll
{
    node *n = new node(val);
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *temp = head; //iterator (will traverse the ll)
    while (temp->next != NULL)
    {
        temp = temp->next;
    }               //we are at last element now
    temp->next = n; // n->next has already value NULL
    n->prev = temp; // for dll
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

node *rotateN(node *&head, int n)
{ //head is pointing 1
    if (n == 0)
    {
        return head;
    }
    node *temp = head; //iterator
    int count = 1;
    while (count < n and temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    node *newHead = temp; //pointing 2 as per example
    while (temp->next != NULL)
    {
        temp = temp->next; //sending to last element
    }                      //temp pointing 5

    //connecting points

    temp->next = head;    //5 next is 1
    head->prev = temp;    //1 prev is 5
    head = newHead->next; //new head is 3
    head->prev = NULL;    //prev of 3 pointing NULL
    newHead->next = NULL; //2 next is null

    return head;
}

int main()
{
    int n = 2;
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);
    head = rotateN(head, n);
    display(head);

    return 0;
}