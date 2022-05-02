/*
61. Rotate List
Medium

3883

1228

Add to List

Share
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k==0)return head;//base
        ListNode* dummy = head;//pointer
        int cnt = 1;//length of ll
        while(dummy->next){//till it reaches the last node
            dummy=dummy->next;
            cnt++;
        }
        dummy->next=head;//circular ll as of now
        k=k%cnt;//if len is greater than k, after ever k rotations we will get original ll
        k = cnt-k;//if k is 2, and cnt is 5, last 2 nodes will come at front, and we will break the 
        //cll from the third, 5-2=3
        while(k--){
            dummy=dummy->next;//as dummy was pointing to last and it was connected to head, it will move from head only
        }
        //dummy is at 3
        head=dummy->next;//head will be at 4
        dummy->next=NULL;//breaking
        return head;
    }
};
int main()
{
    
    return 0;
}