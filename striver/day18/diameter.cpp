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
    int height(TreeNode* node, int& diameter) {
        if (!node)  return 0;
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh);//diameter
        return 1 + max(lh, rh);//for returning
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
