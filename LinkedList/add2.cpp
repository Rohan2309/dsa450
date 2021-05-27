/*
Add two numbers represented by linked lists 

Given two numbers represented by two linked lists of size N and M. 
The task is to return a sum list. The sum list is a linked list representation of the addition of two input 
numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
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

//iterative way
node *reverse(node *&head) //returning new head of reversed LL
{
    node *prevptr = NULL;
    node *currentptr = head;
    node *nextptr;
    while (currentptr != NULL)
    {
        nextptr = currentptr->next; //already next pointer is increaing at the start of loop
        currentptr->next = prevptr;

        prevptr = currentptr;
        currentptr = nextptr;
    }
    return prevptr; //new head
}

node *addTwo(node *head1, node *head2)
{
    int sum = 0, carry = 0;
    head1 = reverse(head1);
    head2 = reverse(head2);
    node *temp;           //putting in result after creating extra node
    node *result = NULL;  //answer
    node *current = NULL; //iterator
    while (head1 != NULL or head2 != NULL)
    {
        sum = carry + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
        //if first value exists then data otherwise 0 and same for second
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;       //10%10 is 0 and any number mod 10 is thatnumber
        temp = new node(sum); //created node of sum because we have to put in answer
        if (result == NULL)   //if we are puuting for first time
        {
            result = temp;
        }
        else //if data already present
        {
            current->next = temp;
        }
        current = temp;
        if (head1)
        {
            head1 = head1->next;
        }
        if (head2)
        {
            head2 = head2->next;
        }
    }
    if (carry > 0)
    { //exception case (99+1)  carry remains 1
        temp = new node(carry);
        current->next = temp;
        current = temp;
    }
    result = reverse(result);
    display(result);
    return result;
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
    addTwo(head1, head2);

    return 0;
}