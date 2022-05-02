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
    private:
    vector<int> a;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
public:
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        int ans = a[k-1];
        return ans;
    }
    
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
