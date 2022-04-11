#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    
    bool helper(TreeNode* root, TreeNode* minV, TreeNode* maxV){
        if(!root)return true;//base
        //in example 2
        //when root is 4
        //left rec -> 3 should be in range between minV and 4
        //right rec -> 6 should be in range between 4 and maxV
        
        if(minV and root-> val <= minV->val)return false;//and when min and max vals are present
        if(maxV and root-> val >= maxV->val)return false;//crosses the range, false case
        //true case
        return helper(root->left,minV,root) and helper(root->right,root,maxV);
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        return helper(root,NULL,NULL);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
