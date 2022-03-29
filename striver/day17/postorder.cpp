/*
145. Binary Tree Postorder Traversal
Easy

3942

136

Add to List

Share
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //iterative 1 stk method
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s;
        TreeNode* cur = root;
        if(!cur)return ans;
        while(!s.empty() or cur){
            if(cur){
                s.push(cur);
                cur=cur->left;
            }
            else{
                TreeNode* temp = s.top()->right;
                if(!temp){
                   temp=s.top();
                    s.pop();
                    ans.emplace_back(temp->val);
                    while(!s.empty() and temp==s.top()->right){
                        temp=s.top();
                        s.pop();
                        ans.emplace_back(temp->val);
                    }
                }
                else{
                    cur=temp;//when temp is not null
                }
            }
            
        }
        
        
        return ans; 
    }
};


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

//post order ->left right root
class Solution {
public:
    //iterative 2 stack method
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        if(!root)return ans;
        s1.push(root);
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
            if(s2.top()->left)s1.push(s2.top()->left);
            if(s2.top()->right)s1.push(s2.top()->right);
        }
        while(!s2.empty()){
            ans.emplace_back(s2.top()->val);
            s2.pop();
        }
        
        return ans; 
    }
};

class Solution {
public:
    //recursive
    void helper(TreeNode* root, vector<int> &ans){
        if(!root)return ;
        helper(root->left,ans);
        helper(root->right,ans);
        ans.emplace_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int>ans;
        helper(root, ans);
        return ans; 
    }
};

int main()
{

    return 0;
}