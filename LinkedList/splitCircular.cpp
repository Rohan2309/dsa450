/*

Split a Circular Linked List into two halves 

Given a Cirular Linked List of size N, split it into two halves circular lists. 
If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists,
t list should have one node more than the second list. The resultant lists should also be circular lists 
and not linear lists.
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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node *temp = head; //iterator (will traverse the ll)

    while (temp->next != head) //upto last pointer
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
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
    node *temp = head;         //iterator (will traverse the ll)
    while (temp->next != head) //upto last pointer
    {
        temp = temp->next;
    }               //we are at last element now
    temp->next = n; // n->next has already value NULL
    n->next = head;
}

void display(node *head) //head by value because we are not mod ll
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}
void splitList(node *head, node **head1_ref, node **head2_ref)
{
    // your code goes here
    node *slow = head;
    node *fast = head->next;
    while (fast != head && fast->next != head)
    { //for circular condition
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;       //start of first half
    *head2_ref = slow->next; //start of second half
    slow->next = *head1_ref; //making circular
    node *temp = *head2_ref; //iterator
    while (temp->next != head)
    { //going to end
        temp = temp->next;
    }
    temp->next = *head2_ref; //making circular
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    return 0;
}