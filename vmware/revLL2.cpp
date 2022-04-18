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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(!head)return NULL;
        ListNode* cur = head;
        ListNode* prev = NULL;
        //left is 2 and right is 4
        while(l>1){//itr ll till we reach idx left
            prev=cur;
            cur=cur->next;
            l--;
            r--;
        }
        //right becomes 2 and left 0
        //prev will be at 1 and curr will be at 2
        //so start is 1 and tail is 2
        ListNode* start = prev;
        ListNode* tail = cur;//to indicate connections at end
        ListNode* tmp = NULL;
        //rev ll till we reach right idx
        while(r>0){//itr loop till r goes 0
            tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
            r--;
        }
        //in between part is reversed
        
        //establish connection with rest of ll
        if(start!=NULL){
            start->next=prev;//when start node is there we connect it with prev
        }
        else{
            head=prev;//if not there then head is prev
        }
        tail->next=cur;
        return head;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
