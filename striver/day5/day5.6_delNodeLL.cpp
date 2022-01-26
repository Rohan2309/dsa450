/*
class Solution {
public:
    void deleteNode(ListNode* node) {
        //node to del will never be tail node
        //we can access the right side of the given node
        node->val = node->next->val;//copying val of right node to current node
        node->next = node->next->next;//skipping the next node
    }
};
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
    void deleteNode(ListNode* node) {
        //node to del will never be tail node
        //we can access the right side of the given node
        node->val = node->next->val;//copying val of right node to current node
        node->next = node->next->next;//skipping the next node
    }
};
int main()
{
    
    return 0;
}