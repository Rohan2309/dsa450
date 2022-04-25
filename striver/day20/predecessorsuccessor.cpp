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
TreeNode * predecessor(TreeNode * root, TreeNode * p) {

        TreeNode* pre = NULL;
        while(root!=NULL){
            if(root->val >= p->val){
                root = root->left;
            }
            else{
                pre = root;
                root = root->right;
            }
        }
        return pre;
    }
    TreeNode* succssesor(TreeNode* root, TreeNode* p) {
        TreeNode*succ = NULL;
        while(root!=NULL){
            if(p->val>=root->val){
                root=root->right;
            }
            else{
                succ=root;//might be answer so storing it
                root=root->left;//while going left
            }
        }
        return succ;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
