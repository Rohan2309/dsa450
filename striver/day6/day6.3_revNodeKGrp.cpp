/*
25. Reverse Nodes in k-Group
Hard

6091

469

Add to List

Share
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

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
    /*
    length=8
    dummy->1->2->3->4..we have
    dummy->3->2->1->4..we want
    initially
    head is pointing at 1
    curr is at 1
    nex is at 2
    pre is at dummy
    change connections
    curr->next = nex->next (1 -> 3)
    nex->next = pre->next (2->1)
    firstly d->1 then now d->2...then it will go d->3
    pre->next=nex(dummy->2)
    nex=curr->next(new nex = 3)
    curr->next = nex->next (1 -> 4)
    nex->next = pre->next (3->2)
    pre->next=nex(dummy->3)
    nex=curr->next(new nex = 4)
    dummy->3->2->1->4..we got
    length = 8-3 = 5
    next group
    pre should be at 1 (pre=curr), earler curr was 1
    curr should be at pre->next (i.e 4)
    nex should be at curr->next (i.e at 5)
    performing operations twice will rev a grp of k nodes
    2nd grp reversed
    len = 5-3 = 2 (left with 2 , not 3 , so stop)
    new nex = 6 and curr is 4
    curr->next =nex->next(4->7)
    return head (dummy->next )
    */
    ListNode* reverseKGroup(ListNode* h, int k) {
        if(!h or k==1){//base case
            return h;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next=h;//we will return
        ListNode * curr = dummy, *nex=dummy, *pre= dummy;
        int len=0;
        while(curr->next){//finding length of linkedlist
            curr=curr->next;
            len++;
        }
        while(len>=k){//8->5->2
            curr=pre->next;
            nex=curr->next;
            for(int i=1; i<k;++i){//k-1 iterations
                curr->next= nex->next;//operations
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;
            }
            pre=curr;//last node of reversed ll
            len-=k;
        }
        return dummy->next;
    }
    
};

int main()
{
    
    return 0;
}