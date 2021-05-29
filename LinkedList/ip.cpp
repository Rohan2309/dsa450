/*
Intersection Point in Y Shapped Linked Lists
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

Example 1:

Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL     
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

void intersect(node *&h1, node *&h2, int pos)
{
    node *temp1 = h1;
    node *temp2 = h2;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

int intersectionPoint(node *h1, node *h2)
{
    int l1 = length(h1);
    int l2 = length(h2);
    int d;
    node *ptr1; // will point to larger ll
    node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = h1;
        ptr2 = h2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = h2;
        ptr2 = h1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL and ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main()
{
    node *head1 = NULL;
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 9);
    display(head1);

    node *head2 = NULL;
    insertAtTail(head2, 3);
    insertAtTail(head2, 4);
    insertAtTail(head2, 5);
    display(head2);
    intersect(head1, head2, 2);
    cout << intersectionPoint(head1, head2) << endl;

    return 0;
}