/*
142. Linked List Cycle II
Medium

6439

436

Add to List

Share
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

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
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next){//base case
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *dummy = head;
        
        while(fast->next and fast->next->next){//checking cycle present or not
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){//if cycle present
                while(slow!=dummy){//slow not at entry point
                    slow=slow->next;
                    dummy=dummy->next;
                }
                return dummy;
            }
        }
        return NULL;
    }
};
int main()
{
    
    return 0;
}