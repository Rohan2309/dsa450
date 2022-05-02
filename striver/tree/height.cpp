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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        int depth = max(x,y) + 1; //1 for root
        return depth;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
