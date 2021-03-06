/*

Check if Circular Linked List

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

bool isCircular(node *head)
{
    if (head == NULL)
    {
        return true;
    }
    node *temp = head->next;
    while (temp != NULL and temp != head) // loop will stop both for circular and not circular
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    isCircular(head) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}