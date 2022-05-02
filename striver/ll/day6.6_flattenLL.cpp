/*
Flattening a Linked List
Medium Accuracy: 33.91% Submissions: 75133 Points: 4
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
Note: The flattened list will be printed using the bottom pointer instead of next pointer.



Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22   35
|           |     |
8          50    40
|                 |
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every
node in a single level.
(Note: | represents the bottom pointer.)


Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |
7          22
|          |
8          50
|
30
Output: 5->7->8->10->19->20->22->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *mergeTwo(Node *a, Node *b)
{                             // a points to first ll head and b 2nd ll head
    Node *temp = new Node(0); // dummy nodes (moves downwards for traversing)
    Node *res = temp;         // always at top (so it can point to next). and return
    while (a and b)
    {
        if (a->data < b->data)
        {                        // if a is small we take val of it
            temp->bottom = a;    // temp->a
            temp = temp->bottom; // res->temp
            a = a->bottom;       // new a (going down)//res->temp->a
        }
        else
        { // if b is small we take val of it
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom; // new b (going down)
        }
        // either of l1 or l2 has taken entirely
    }

    // if l1 is still left
    if (a)
        temp->bottom = a;
    // if l2 is left
    else
        temp->bottom = b;

    return res->bottom; // head of flatten linkedlist
}
/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
    // Your code here
    if (!root or !root->next)
        return root;                  // base
    root->next = flatten(root->next); // going to rightmost, simply pointing to root next, whatever it returns
    // creating a connection

    // merge
    root = mergeTwo(root, root->next);
    return root;
}

int main()
{

    return 0;
}