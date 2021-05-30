/*
Reverse a Doubly Linked List

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

node *revDll(node *&head)
{
    node *curr = head;
    if (curr == NULL or curr->next == NULL) //base case
    {
        return head;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    head = curr;               // last element head
    curr->next = curr->prev;   //reversing
    curr->prev = NULL;         // head prev pointing to null
    curr = curr->next;         // moving towards left
    while (curr->prev != NULL) /*moving towards left (one by one) *MIDDLE ELEMENTS* */
    {
        node *temp = curr->next; //stores next value of curr node so that it doesn't gets lost
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->next;
    }
    //for first element
    curr->prev = curr->next;
    curr->next = NULL;
    return head;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAtHead(head, 4);
    display(head);
    revDll(head);
    display(head);

    return 0;
}