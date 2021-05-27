/*

Detect Loop in linked list 
and deletes
hare and tortoise
Floyd algo
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

bool detectCycle(node *&head)
{
    node *fastptr = head; //hare
    node *slowptr = head; //tortoise

    while (fastptr != NULL and fastptr->next != NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (fastptr == slowptr)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(node *&head)
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
    if (slowptr == head) //exception case (slowptr and fastptr both at start point)
    {
        while (fastptr->next != slowptr)
        {
            fastptr = fastptr->next; //taking fastptr till last
        }
        fastptr->next = NULL;
    }
    else if (slowptr == fastptr)
    {
        slowptr = head; //tortoise at beginning
        while (slowptr->next != fastptr->next)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }
    }
    fastptr->next = NULL; //breaking loop and making sll
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
    cout << detectCycle(head) << endl;
    removeCycle(head);
    cout << detectCycle(head) << endl;
    display(head);
    return 0;
}