#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
private: vector<vector<int>>ans;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)return {};
        queue<TreeNode *> q;
        q.push(root); //pushing root node in q
        while (!q.empty())
        {
            int cnt = q.size();//for each level the loop will run cnt times
            vector<int> tmp;//for storing level
            for(int i=0; i<cnt; ++i){
                TreeNode *t = q.front();    //storing in node
                q.pop(); //current element
                if (t->left) q.push(t->left);
                if (t->right)q.push(t->right);
                tmp.push_back(t->val); //storing in level vect
            }
             ans.push_back(tmp);
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
