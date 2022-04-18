#include<bits/stdc++.h>
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

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
