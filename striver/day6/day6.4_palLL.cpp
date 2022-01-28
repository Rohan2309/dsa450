/*
234. Palindrome Linked List
Easy

7691

499

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

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode * revList(ListNode* head){
        ListNode *prevPtr = NULL;
        ListNode *nextPtr;
        ListNode *curr = head;
        while(curr){
            nextPtr = curr->next;
            curr->next=prevPtr;
            prevPtr=curr;
            curr=nextPtr;
        }
        return prevPtr;//pointing towards last, new head
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next){//base case
            return true;
        }
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next and fast->next->next ){
            slow= slow->next;
            fast = fast->next->next;
        }
        //middle element in slow
        
        slow->next = revList(slow->next);//reverse the right half from slow, which is mid to end
        //connecting the reversed portion of right halft to the left of linked list
        slow=slow->next;//pointing to first pos of right half
        
        fast=head;//first pos of left linked list
        //checking palindrome
        while(slow){
            if(fast->val!=slow->val){
                return false;
            }
            fast=fast->next;
            slow=slow->next;
        }
        return true;
        
            
    }
};
int main()
{
    
    return 0;
}