
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
    TreeNode* helper(vector<int>& a, int st,int en){
        int mid = (st+en)/2;
        if(st>en)return NULL;//binary search base case
        TreeNode* root = new TreeNode(a[mid]);//root is array middle element
        root->left = helper(a, st, mid-1);
        root->right = helper(a, mid+1, en);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& a) {
        if(a.size()==0)return NULL;
        int n = a.size();
        int st = 0;
        int en = n-1;
        return helper(a, st, en);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

