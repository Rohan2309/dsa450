/*
Move last element to front of a given Linked List

Write a function that moves the last element to the front in a given Singly Linked List.
For example, if the given Linked List is 1->2->3->4->5, then the function should change the
list to 5->1->2->3->4.
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

node *lastFront(node *&head)
{
    if (head == NULL or head->next == NULL)
    {
        cout << "Empty LinkedList";
    }
    node *prev = NULL;
    node *temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->next = head;
    head = temp;
    return head;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 5);
    insertAtTail(head, 4);
    insertAtTail(head, 2);
    display(head);
    node *newHead = lastFront(head);
    display(newHead);

    return 0;
}