/*
Sort a k sorted doubly linked list
Given a doubly linked list containing n nodes, where each node is at most k away from its target position 
in the list. The problem is to sort the given doubly linked list. 
For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list, can be at 
positions 5, 6, 7, 8, 9 in the given doubly linked list.

*O(nk)*
insertion sort  {a no n can lie i-k to i+ k range}
first loop will be O(n)
second loop range i to (i-k) 
if we find it is smaller then insert


* We are doing on O(nlogk) approach -> code below*

mean heap gives lowest value max heap gives highest value
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

struct compare //{changing to min heap}
{
    bool operator()(node *first, node *second)
    {
        return first->data > second->data; // gives  ascending
    }
};
node *kSort(node *&head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    priority_queue<node *, vector<node *>, compare> pq; //compare {by default max heap}
    node *newHead = NULL;
    node *curr; //iterator

    for (int i = 0; head != NULL and i <= k; i++) //0 to k every element inside priority queue
    {
        pq.push(head);
        head = head->next;
    }

    while (!pq.empty())
    {
        if (newHead == NULL) //if first time in pq
        {
            newHead = pq.top();
            newHead->prev = NULL; //dll first head (prev points null)
            curr = newHead;
        }
        else //atleast one node is there
        {
            curr->next = pq.top();
            pq.top()->prev = curr;
            curr = pq.top();
        }
        pq.pop(); //after popping we are adding to pq

        if (head != NULL) //if more nodes are left
        {
            pq.push(head);
            head = head->next;
        }
    }
    curr->next = NULL; //last will point towards null
    return newHead;
}

int main()
{
    int k = 2;
    node *head = NULL;
    insertAtTail(head, 3);
    insertAtTail(head, 6);
    insertAtTail(head, 2);
    insertAtTail(head, 12);
    insertAtTail(head, 56);
    insertAtTail(head, 8);
    display(head);
    head = kSort(head, k);
    display(head);

    return 0;
}