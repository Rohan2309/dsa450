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

class BSTIterator
{
    stack<TreeNode *> s;
    bool reverse = true; // before
public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *tmpNode = s.top();
        s.pop();
        if (!reverse)
            pushAll(tmpNode->right); // for next
        else
            pushAll(tmpNode->left); // for before
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            s.push(node);
            if (reverse == true)
            { // right because before
                node = node->right;
            }
            else
            {
                node = node->left; // left because next
            }
        }
    }
};
class Solution
{

public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        BSTIterator l(root, false); // itr for left (next)
        BSTIterator r(root, true);  // before
        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next(); // increasing th left pointer
            else
                j = r.next(); // increasing the right pointer
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
