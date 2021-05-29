/*
Intersection of two sorted Linked lists 

Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.
Example 2:

Input:
L1 = 10->20->40->50
L2 = 15->40
Output: 40
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

node *intersection(node *h1, node *h2)
{
    node *ans = NULL; //resultant ll
    node *ptr1 = h1;
    node *ptr2 = h2;
    node *temp = NULL;    //iterator
    while (ptr1 and ptr2) //both are not finished yet
    {
        if (ptr1->data == ptr2->data)
        {
            if (ans == NULL) //first data
            {
                node *t = new node(ptr1->data);
                ans = t;
                temp = t;
            }
            else
            {
                node *t = new node(ptr1->data);
                temp->next = t;
                temp = temp->next;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else
        {
            if (ptr1->data < ptr2->data)
            {
                ptr1 = ptr1->next;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
    }
    display(ans);
    return ans;
}

int main()
{
    node *head1 = NULL;
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    display(head1);

    node *head2 = NULL;
    insertAtTail(head2, 3);
    insertAtTail(head2, 4);
    insertAtTail(head2, 5);
    display(head2);
    intersection(head1, head2);

    return 0;
}