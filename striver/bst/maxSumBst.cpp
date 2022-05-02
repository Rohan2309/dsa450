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

class Solution {
    struct S {
        bool isBST;
        int minVal, maxVal, sum;
    };
    
    S helper(TreeNode *node, int &res) {
        if (!node) return { true, INT_MAX, INT_MIN, 0 };// An empty tree is a BST of size 0.
        //doing postorder traversal
        // Get values from left and right subtree of current tree.
        S l = helper(node->left, res);
        S r = helper(node->right, res);
    // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (l.isBST and r.isBST and l.maxVal < node->val and r.minVal > node->val) {
            int sum = l.sum + r.sum + node->val;
            res = max(res, sum);
            return { true, min(l.minVal, node->val), max(r.maxVal, node->val), sum };
        } else {
            return { false, INT_MIN, INT_MAX, 0 };
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
