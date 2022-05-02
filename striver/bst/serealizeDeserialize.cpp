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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";//empty string
        string ans="";
        queue<TreeNode*>q;
        q.push(root);
        //doing level order traversal
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur==NULL)ans.append("$,");//taking $ for null values
            else ans.append(to_string(cur->val)+',');
            if(cur){//insert also if left and right is null
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream ss(data);
        string t;
        getline(ss,t,',');
        TreeNode * root = new TreeNode(stoi(t));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * cur = q.front();
            q.pop();
            getline(ss,t,',');//for left child
            if(t=="$"){
                cur->left= NULL;//attaching null to the left
            }
            else{
                TreeNode * lNode = new TreeNode(stoi(t));
                cur->left=lNode;
                q.push(lNode);
            }
            getline(ss,t,',');//for right child
            if(t=="$"){
                cur->right= NULL;
            }
            else{
                TreeNode * rNode = new TreeNode(stoi(t));
                cur->right=rNode;
                q.push(rNode);
            }
        }
        return root;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
