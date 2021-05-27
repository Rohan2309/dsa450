/*
Add 1 to a number represented as linked list 

A number N is represented in Linked List such that each digit corresponds to a node in linked list.
 You need to add 1 to it.

 Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
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

node *addOne(node *&head)
{
    head = reverse(head);
    bool f = true;
    node *current = head;
    while (current != NULL and f == true)
    {
        if (current->data == 9 and current->next == NULL)
        {
            current->data = 1;
            node *temp = new node(0);
            temp->next = head;
            head = temp;
            current = current->next; //while loop breaks(null)
        }
        else if (current->data == 9)
        {
            current->data = 0;
            current = current->next;
        }
        else
        {
            current->data = current->data + 1;
            current = current->next;
            f = false;
        }
    }
    head = reverse(head);
    return head;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 9);
    insertAtTail(head, 9);
    insertAtTail(head, 9);
    display(head);
    addOne(head);
    display(head);

    return 0;
}