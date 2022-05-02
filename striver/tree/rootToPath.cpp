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

bool f(TreeNode *a, int b, vector<int> &ans)
{
    if (!a)
        return false;
    ans.push_back(a->val);
    if (a->val == b)
        return true;
    if (f(a->left, b, ans) or f(a->right, b, ans))
        return true;
    ans.pop_back();
    return false;
}
vector<int> solve(TreeNode *A, int B)
{
    vector<int> ans;
    if (!A)
        return ans;
    f(A, B, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
