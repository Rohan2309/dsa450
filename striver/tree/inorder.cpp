/*
94. Binary Tree Inorder Traversal
Easy

7236

323

Add to List

Share
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
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
    //morris traversal method - threaded binary tree 
    
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur = root;//initial val
        vector<int>ans;
        while(cur){
            //when no left we push root ele and move to right
            if(!cur->left){
                ans.emplace_back(cur->val);
                cur= cur->right;
            }
            else{//when left
                TreeNode* prev = cur->left;//pointer to left of root
                while(prev->right and prev->right!=cur){//going to the rightmost child
                    prev=prev->right;
                }
                if(!prev->right){//when null
                    prev->right=cur;//making a connection/thread
                    cur=cur->left;//moving to next left
                }
                else{//when connection is already present
                    prev->right=NULL;//breaking connection
                    ans.emplace_back(cur->val);
                    cur=cur->right;//already visited left so visit right
                }
            }
        }
        return ans;
    }

};

class Solution {
public:
    //iterative method
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode* node = root;//initial val
        vector<int>ans;
        while(true){
            //creating auxiliary stk
            if(node){//if node is present
                s.push(node);//push that node
                node= node->left;//move to next node
            }
            else{//when null
                if(s.empty())break;// exit case
                node= s.top();//we take top element in ans
                s.pop();
                ans.emplace_back(node->val);
                node= node->right;//move to the right
            }
        }
        return ans;
    }

};

class Solution {
public:
    //recursive method
    void helper(TreeNode* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        helper(root,ans);
        return ans;
    }

};

int main()
{

    return 0;
}