/*
108. Convert Sorted Array to Binary Search Tree
Easy

4864

309

Add to List

Share
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,3] and [3,1] are both a height-balanced BSTs.
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
TreeNode *helper(vector<int> &a, int st, int en)
{
    int mid = (st + en) / 2;
    if (st > en)
    { //binary search approach , base case
        return NULL;
    }
    TreeNode *root = new TreeNode(a[mid]); //root is array middle element
    root->left = helper(a, st, mid - 1);
    root->right = helper(a, mid + 1, en);

    return root;
}
TreeNode *sortedArrayToBST(vector<int> &a)
{
    if (a.size() == 0)
    { //base case
        return NULL;
    }
    int n = a.size();
    int st = 0;
    int en = n - 1;
    return helper(a, st, en);
}
int main()
{

    return 0;
}