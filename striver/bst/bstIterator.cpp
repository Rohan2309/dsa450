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

class BSTIterator {
private:
    stack<TreeNode*>s;
    void pushAll(TreeNode* root){//push all left elements
        while(root){
            s.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);//pushing node and all left eles
    }
    
    int next() {
        TreeNode*node=s.top();//top ele is next
        s.pop();
        pushAll(node->right);//if right exist we go right and push all the left
        return node->val;
    }
    
    bool hasNext() {
        return !s.empty();//if s is non empty we do have eles
        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
