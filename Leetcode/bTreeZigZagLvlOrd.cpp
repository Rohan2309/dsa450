/*
103. Binary Tree Zigzag Level Order Traversal
Medium

4260

139

Add to List

Share
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
*/

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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root)
    {
        return {};
    }
    vector<vector<int>> ans;
    bool rev = true;
    deque<TreeNode *> q;
    q.push_back(root);
    while (!q.empty())
    {                     //normally we do push back
        vector<int> temp; //vect for a given level
        int cnt = q.size();
        deque<TreeNode *> dq; //internal dq
        for (int i = 0; i < cnt; i++)
        {
            TreeNode *t = q.front();
            temp.push_back(t->val);
            q.pop_front();
            if (rev)
            {
                if (t->left)
                {
                    dq.push_front(t->left);
                }
                if (t->right)
                {
                    dq.push_front(t->right);
                }
            }
            else
            {
                if (t->right)
                {
                    dq.push_front(t->right);
                }
                if (t->left)
                {
                    dq.push_front(t->left);
                }
            }
        }
        q.insert(q.end(), dq.begin(), dq.end()); //in outer q we insert
        ans.push_back(temp);
        rev = !rev;
    }
    return ans;
}

int main()
{

    return 0;
}