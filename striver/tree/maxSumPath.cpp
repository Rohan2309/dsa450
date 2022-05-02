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
    int mx=INT_MIN;
    int f(TreeNode* root,int &mx){
        if(!root)return 0;
        //not considering negative sum
        int maxL = max(0,f(root->left,mx));//will have maximum in left side
        int maxR = max(0,f(root->right,mx));//in right side
        mx = max(mx, root->val+maxL+maxR);//will have the maximum path
        return (root->val + max(maxL,maxR));//while backtraking will choose only 1 side
    }
public:
    int maxPathSum(TreeNode* root) {
        f(root,mx);
        return mx;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
