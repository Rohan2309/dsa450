/*
21. Merge Two Sorted Lists
Easy

10148

970

Add to List

Share
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;//base cases
        if(!l2)return l1;
        if(l1->val>l2->val) swap(l1,l2);//l1 is always small
        ListNode * res = l1;//head of resultant node
        while(l1 and l2){
            ListNode* tmp= NULL;//to remember the last node pointing till an iteration
            while(l1 and l1->val<=l2->val){//till l1 is smaller than l2
                tmp=l1;//last node opinting in l1
                l1=l1->next;
                
            }
            tmp->next=l2;//new connection
            swap(l1,l2);//again smaller value assigned as l1
        }
        return res;
        
    }
};

int main()
{
    
    return 0;
}