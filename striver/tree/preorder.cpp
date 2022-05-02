/*
144. Binary Tree Preorder Traversal
Easy

3837

121

Add to List

Share
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 
*/

#include <bits/stdc++.h>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    //iterative
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s;
        if(!root)return ans;
        s.push(root);
        while(!s.empty()){
            root=s.top();
            s.pop();
            ans.emplace_back(root->val);
            //first right then left as stk uses lifo
            if(root->right)s.push(root->right);
            if(root->left)s.push(root->left);
        }
        
        return ans;
    }
};

class Solution {
public:
    //recursive
    void helper(TreeNode* root, vector<int> &ans){
        if(!root)return ;
        ans.emplace_back(root->val);
        helper(root->left,ans);
        helper(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        helper(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}