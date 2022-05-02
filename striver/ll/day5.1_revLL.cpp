/*
206. Reverse Linked List
Easy

9526

166

Add to List

Share
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prevPtr = NULL;
        ListNode* cur = head;
        ListNode* nextPtr;
        while(cur!=NULL){
            nextPtr = cur->next;
            cur->next = prevPtr;
            
            prevPtr= cur;
            cur = nextPtr;
        }
        return prevPtr; //new head
    }
};

int main()
{
    
    return 0;
}