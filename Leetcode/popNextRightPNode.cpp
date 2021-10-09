/*
116. Populating Next Right Pointers in Each Node
Medium

4462

197

Add to List

Share
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:


Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if (!root)
    { //base case
        return NULL;
    }
    Node *lft = root; //initializing
    while (lft != NULL and lft->left != NULL)
    {                     //if it has a next level to it
        Node *head = lft; //temp var, for that level
        while (head != NULL)
        {                                   //while root is present
            head->left->next = head->right; //pointing left children to right children
            if (head->next != NULL)
            {                                         //if next is already null then no need to point right-> next to (left of next head)
                head->right->next = head->next->left; //connecting right to left of next head
            }
            head = head->next; //moving to next head in same level
        }
        lft = lft->left; //next level
    }
    return root;
}
int main()
{

    return 0;
}