/*
101. Symmetric Tree
Easy

7320

187

Add to List

Share
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isMirror(TreeNode *t1, TreeNode *t2)
{
    if (!t1 or !t2)
    {                      //if any one of them is null
        return (t1 == t2); //only way it can be true when both are null
    }
    //when not null
    if (t1->val != t2->val)
    { //when values are not same
        return false;
    }
    //if values are same
    return (isMirror(t1->left, t2->right) and isMirror(t1->right, t2->left));
}

bool isSymmetric(TreeNode *root)
{
    if (!root)
    {
        return true;
    }
    else
    {
        return isMirror(root->left, root->right);
    }
}

int main()
{

    return 0;
}