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
private: TreeNode*prev=NULL;
public:
    void flatten(TreeNode* root) {
        if(!root)return;
        flatten(root->right);//going in extreme right side of bt
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
