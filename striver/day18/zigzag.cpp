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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        bool rev = true;//left to right
        queue<TreeNode*>q;
        q.push(root);//init
        while(!q.empty()){
            int sz = q.size();
            vector<int>temp(sz);//vect for a given level
            for(int i=0; i<sz ; ++i){
                TreeNode * t = q.front();
                q.pop();
                int idx = (rev)?i:(sz-1-i);//if rev true then first index otherwise last
                temp[idx]=t->val;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            rev =!rev;//changing direction
            ans.push_back(temp);
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
