/*
Find pairs with given sum in doubly linked list
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

void pairSum(node *head, int x)
{
    node *first = head;
    node *second = head;
    while (second->next != NULL)
    {
        second = second->next; //moving second pointer towards last
    }
    bool found = false;
    while (first != second and second->next != first) // become same or cross eachother
    {
        if (first->data + second->data == x)
        {
            found = true;
            cout << "(" << first->data << ", "
                 << second->data << ")" << endl;
            first = first->next;
            second = second->prev;
        }
        else
        {
            if (first->data + second->data < x)
            {
                first = first->next; //sorted order dll (left side will be less)
            }
            else
            {
                second = second->prev;
            }
        }
    }
    if (found == false)
    {
        cout << "No pair found" << endl;
    }
}

int main()
{
    int x = 3;
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    display(head);
    pairSum(head, x);
    return 0;
}