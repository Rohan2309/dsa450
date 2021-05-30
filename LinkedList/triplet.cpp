/*
Count triplets in a sorted doubly linked list whose sum is equal to a given value x

*Map approach(O(N)) space*
if x = 17 and dll consists 1,2,3,4,5,6,7,8,9
first loop (1 to 9)
x = 17-1 = 16
take map
loop from second element
if element (x-element) {16-2} not present in map push element
if element present in map (found triplet) {increase counter}
pop map

* doing O(N)*
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

int countPairs(node *first, node *second, int val)
{
    int count = 0;
    // cross eachother ( second -> next == first ) or become same ( second == first)
    while (first != NULL and second != NULL and first != second and second->next != first)
    {
        if (first->data + second->data == val) // pair found
        {
            count++;
            first = first->next;
            second = second->prev;
        }
        else if (first->data + second->data > val)
        {
            second = second->prev;
        }
        else
        {
            first = first->next;
        }
    }
    return count;
}
int triplet(node *head, int x)
{
    if (head == NULL) //list is empty (base case)
    {
        return 0;
    }
    node *curr;  //for iterator (first loop)
    node *first; //first pointer
    node *last;  //last pointer
    int count = 0;
    last = head;
    while (last->next != NULL) // last pointer at last of linked list
    {
        last = last->next;
    }
    for (curr = head; curr != NULL; curr = curr->next) // traversing the dll
    {
        first = curr->next; //for each curr node
        count += countPairs(first, last, x - curr->data);
    }
    return count;
}
int main()
{

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    int x = 17;
    display(head);
    cout << "Count = "
         << triplet(head, x);

    return 0;
}