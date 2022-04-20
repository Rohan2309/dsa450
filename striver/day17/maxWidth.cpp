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
    queue<pair<TreeNode*,int>>q;//root and index
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int width=0;
        int first, last;
        q.push({root,0});//initial config
        while(!q.empty()){
            int sz= q.size();
            int x = q.front().second;//taking first guy's idx (min idx possible on lvl)
            for(int i=0; i<sz; ++i){//traversing q for each level
                int y = q.front().second-x;//current idx, subttracted with min idx of level
                TreeNode * node = q.front().first;
                q.pop();
                if(i==0)first=y;//if first ele of q
                if(i==sz-1)last=y;//if last ele of q
                if(node->left)q.push({node->left,(long long)y*2+1});
                if(node->right)q.push({node->right,(long long)y*2+2});
            }
            width=max(width,last-first+1);//max width
        }
        return width;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
