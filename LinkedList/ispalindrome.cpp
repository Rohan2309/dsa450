/*

Check if Linked List is Palindrome 

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

bool isPalindrome(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL) // getting mid value
    {
        slow = slow->next;
        fast = fast->next->next;
    } //middle element in slow

    //reverse from slow to last
    node *prev = NULL;
    node *next;
    node *current = slow;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    fast = head; // at the start
    //prev is pointing at the last
    while (prev != NULL)
    {
        if (fast->data != prev->data)
        {
            return false;
        }
        else
        {
            fast = fast->next;
            prev = prev->next;
        }
    }
    return true;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    display(head);
    cout << isPalindrome(head);

    return 0;
}