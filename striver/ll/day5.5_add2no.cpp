/*
2. Add Two Numbers
Medium

15981

3427

Add to List

Share
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();//dummy node
        ListNode *temp = dummy;//copy of dummy node, for iteration
        int sum =0;
        int carry =0;
        while(l1 or l2  or carry){
            sum=0;//sum will be reinitialized to 0 at the start of every iteration
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;//adding carry value to sum
            carry = sum/10;//carry will always be /10 as it will be only first value
            ListNode *newNode = new ListNode(sum%10);//only single digit
            temp->next = newNode;//temp will point to new node created
            temp=temp->next;//iteration
        }
        return dummy->next;//it will be the head of the added linked list formed
    }
};
int main()
{
    
    return 0;
}