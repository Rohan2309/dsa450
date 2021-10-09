/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

6605

162

Add to List

Share
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
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
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> hash; //putting inoder in hash map
    for (int i = 0; i < inorder.size(); i++)
    {
        hash[inorder[i]] = i; // 9->0, 3->1, 15->2....6->4
    }

    TreeNode *root = helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, hash);
    return root;
}

TreeNode *helper(vector<int> &preorder, int pSt, int pEn, vector<int> &inorder, int iSt, int iEn, map<int, int> &hash)
{

    //base case, if we dont have any preorder or inorder value
    if (pSt > pEn or iSt > iEn)
    {
        return NULL;
    }
    //1st of preoder, is always the parent node
    TreeNode *root = new TreeNode(preorder[pSt]); //initial root at first level of recursion call

    //position of root, in inorder
    int inPos = hash[root->val]; //will return position from hash map

    //how many numbers are on the left, in inorder from the root
    int lft = inPos - iSt;

    //for the left sub tree     { //starts from the next  //takes no of elements in left } for preoder
    //{ //starts from the start  //takes all elements in left } for inorder
    root->left = helper(preorder, pSt + 1, pSt + lft, inorder, iSt, inPos - 1, hash);

    //for the right sub tree     { //starts from the start+ no of ele in left + 1  //till end} for preoder
    //{ //starts from pos +1  //takes all elements till end } for inorder
    root->right = helper(preorder, pSt + lft + 1, pEn, inorder, inPos + 1, iEn, hash);

    return root;
}
int main()
{

    return 0;
}