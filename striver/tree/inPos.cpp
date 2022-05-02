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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size())return NULL;
        map<int,int> hm;//node val and index
        for (int i=0;i<inorder.size();++i)hm[inorder[i]] = i; //putting inoder in hash map
        return helper(inorder, 0, inorder.size()-1, postorder, 0, 
                              postorder.size()-1,hm);
    }
    
    
    TreeNode* helper(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int,int> &hm){
        if (ps>pe or is>ie) return NULL;
        //initial root at first level of recursion call
        TreeNode* root = new TreeNode(postorder[pe]);//last of postorder, is always the parent node
        int lft = hm[root->val]; //position of root, in inorder//will return position from hash map (of root)//how many numbers are on the left, in inorder from the root
        root->left = helper(inorder, is, lft-1, postorder, ps, ps+lft-is-1, hm);
        //for the left sub tree     { //starts from the start  //takes no of elements in left } for postorder
        //{ //starts from the start  //takes all elements in left } for inorder
        root->right = helper(inorder,lft+1, ie, postorder, ps+lft-is, pe-1, hm);
         //for the right sub tree     { //starts from the start+ no of ele in left   //till end -1} for postorder
        //{ //starts from pos +1  //takes all elements till end } for inorder
        
        return root;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
