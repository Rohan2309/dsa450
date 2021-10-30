/*
148. Sort List
Medium

5259

196

Add to List

Share
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
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
    ListNode* merge(ListNode *a, ListNode *b){
        if(!b){ //when we dont have the 2nd ll
            return a;
        }
        if(!a){//when we dont have the 1st ll
            return b;
        }
        if(a->val < b->val){ //then first node will be a
            a->next = merge(a->next,b);//2nd node will be smaller between the next to a , and b
            return a;
        }
        else{
            b->next = merge(a, b->next);
            return b;
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next){ // base case , when 0 node or 1 node
            return head;
        }
        //divide linkedlist (equally or unequally, does not matter)
        ListNode * slowPtr = head;
        ListNode * fastPtr = head->next;
        while(fastPtr and fastPtr->next){
            slowPtr= slowPtr->next;
            fastPtr= fastPtr->next->next;
        }
        //breaking linkedlist
        ListNode* newNode = slowPtr->next;//reference, for new head for the other half of ll
        slowPtr->next = NULL;//breaking links
        
        return merge(sortList(head), sortList(newNode));//brealing into further pieces
    }
};


int main()
{
    
    return 0;
}