/*
234. Palindrome Linked List
Easy

6526

476

Add to List

Share
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    //middle element in slow

    //rev from slow to last

    ListNode *prevPtr = NULL;
    ListNode *nextPtr;
    ListNode *current = slow;

    while (current != NULL)
    {
        nextPtr = current->next;
        current->next = prevPtr;

        prevPtr = current;
        current = nextPtr;
    }
    //revrsed
    //now prev pointing towards last

    fast = head; //ast start
    //checking if pallindrope from two sides
    while (prevPtr != NULL)
    {
        if (fast->val != prevPtr->val)
        {
            return false;
        }
        else
        {
            fast = fast->next;
            prevPtr = prevPtr->next;
        }
    }
    return true;
}

int main()
{

    return 0;
}