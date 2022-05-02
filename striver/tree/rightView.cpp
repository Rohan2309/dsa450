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
    private: vector<int>ans;
public:
    //pre order -> root left right
    //reverse pre order -> root right left
    
    void f(TreeNode* root, int lvl){
        if(!root)return;
        if(lvl==ans.size())ans.push_back(root->val);//when first guy in level
        f(root->right,lvl+1);//first right
        f(root->left,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        f(root,0);
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
