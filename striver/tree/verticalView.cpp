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

class Solution
{
private:
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> mp;      // vertical, level, values (can have same)
    queue<pair<TreeNode *, pair<int, int>>> q; // node, vertical, level
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (!root)
            return ans;
        q.push({root, {0, 0}}); // initial vertical and level
        while (!q.empty())
        { // level order traversal
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;                     // node
            int x = it.second.first, y = it.second.second; // x->vertical,y->level
            mp[x][y].insert(node->val);                    // inserting to multiset
            if (node->left)
            {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        for (auto it : mp)
        {                  // whole map
            vector<int> v; // for each verical
            // level and multiset, //insering entire multiset at the end, for each level
            for (auto itr : it.second)
                v.insert(v.end(), itr.second.begin(), itr.second.end());
            ans.push_back(v);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
