/*
Merge Sort for Linked List 
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:

Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.
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
void findMid(node *curr, node **first, node **second)
{
    node *fast;
    node *slow;
    slow = curr;
    fast = curr->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *first = curr;
    *second = slow->next;
    slow->next = NULL;
}

node *mergeBoth(node *first, node *second)
{
    node *ans = NULL;
    if (!first)
    {
        return second;
    }
    else if (!second)
    {
        return first;
    }
    if (first->data <= second->data)
    {
        ans = first;
        ans->next = mergeBoth(first->next, second);
    }
    else
    {
        ans = second;
        ans->next = mergeBoth(first, second->next);
    }
    return ans;
}
void mergeSorting(node **head) //**changes won't affect outside
{
    node *curr = *head;
    node *first;
    node *second;
    if (!curr or !curr->next) //only one value or no value is present
    {
        return;
    }
    findMid(curr, &first, &second);
    mergeSorting(&first);
    mergeSorting(&second);
    *head = mergeBoth(first, second);
}

node *mergeSort(node *head)
{
    mergeSorting(&head); //& as we are updating head
    return head;
}
int main()
{
    node *head1 = NULL;
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 2);
    display(head1);
    mergeSort(head1);
    display(head1);
    return 0;
}