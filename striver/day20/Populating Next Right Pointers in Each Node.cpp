#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        Node* curr = root;//initializing
        while(curr->left!=NULL){//if it has a next level to it
            Node* tmp = curr;//temp var, for that level
            while(curr!=NULL){//while root is present
                curr->left->next = curr->right;//pointing left children to right children
                if(curr->next != NULL){//if next is already null then no need to point right-> next to (left of next head)
                    curr->right->next = curr->next->left;//connecting right to left of next head
                }
                curr = curr->next;//moving to next head in same level
            }
            curr= tmp->left;//next level
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
