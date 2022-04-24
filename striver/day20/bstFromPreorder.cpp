
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
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return helper(A, i, INT_MAX);//current upper bound
    }

    TreeNode* helper(vector<int>& A, int& i, int bound) {
        if (i == A.size() or A[i] > bound) return NULL;//if goes out of bound
        TreeNode* root = new TreeNode(A[i++]);
        root->left = helper(A, i, root->val);//must be smaller than current node val
        root->right = helper(A, i, bound);//must be smaller than prev node val
        return root;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
