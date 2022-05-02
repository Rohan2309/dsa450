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
    private:
    int f(TreeNode* root){
        if(!root)return 0;
        int lh = f(root->left);
        if(lh==-1)return -1;//bychance lh return -1 return -1
        int rh = f(root->right);
        if(rh==-1)return -1;
        if(abs(lh-rh)>1)return -1;//bs return -1
        return max(lh,rh)+1;//return height
    }
public:
    bool isBalanced(TreeNode* root) {
        return f(root)!=-1;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
