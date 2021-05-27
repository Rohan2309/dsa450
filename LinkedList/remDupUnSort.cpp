/*
Remove duplicates from an unsorted linked list

Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted
 Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, 
 all others duplicates are to be removed.

Example 1:

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4
Example 2:

Input:
N = 5
value[] = {2,2,2,2,2}
Output: 2
Explanation:Given linked list elements are
2->2->2->2->2, in which 2 is repeated. So,
we will delete the extra repeated elements
2 from the linked list and the resultant
linked list will contain only 2.

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

node *removeDuplicate(node *&head)
{

    node *current = head;
    map<int, int> m; //to store values(int,int)

    m[current->data] = 1;
    node *previous = current;
    current = current->next; //starting loop from second (curr is second and prev is first)

    while (current != NULL) //to traverse
    {
        if (m[current->data]) //exists in ll
        {
            previous->next = current->next;
            free(current); //deleting current node
        }
        else //first time in ll
        {
            m[current->data] = 1;
            previous = current;
        }
        current = previous->next;
    }
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
    removeDuplicate(head);
    display(head);
    return 0;
}