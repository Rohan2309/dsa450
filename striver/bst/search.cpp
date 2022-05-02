
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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        TreeNode *node=new TreeNode(); //new node to return
        if(val<root->val) node = searchBST(root->left,val);//when smaller search left
        else if(val>root->val) node = searchBST(root->right,val);//when bigger search right
        else node=root;//when found
        return node;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

