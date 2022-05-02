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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if root becomes null we return null
        //or we rach any of the given nodes we return that
        if(!root or root==p or root==q)return root;//base
        //moving to left and right
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        //while coming back
        if(!l)return r;//if left returns null taking right guy
        else if(!r)return l;//vice versa
        //if both cond fails, then p and q lies under root
        else return root;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
