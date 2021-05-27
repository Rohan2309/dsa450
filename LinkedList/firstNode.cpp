/*
Find first node of loop in a linked list

Write a function findFirstLoopNode() that checks whether a given Linked List contains a loop. 
If the loop is present then it returns point to the first node of the loop. Else it returns NULL.
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

node *firstNode(node *&head)
{
    node *fastptr = head; //hare
    node *slowptr = head; //tortoise
    while (fastptr->next != NULL and slowptr != NULL and fastptr != NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (slowptr == fastptr)
        {
            break;
        }
    }
    if (slowptr != fastptr) //no loop
    {
        return NULL;
    }

    slowptr = head; //tortoise at beginning
    while (slowptr != fastptr)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next;
    }
    return slowptr;
}

void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    makeCycle(head, 3);
    node *res = firstNode(head);
    if (res == NULL)
    {
        cout << "Loop does not exists";
    }
    else
    {
        cout << "Loop starting node is " << res->data;
    }
    return 0;
}