#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    private:
    vector<int>v;
    void inorder(Node* root){
        if(!root)return;
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }
    public:
    int kthLargest(Node *root, int K)
    {
        //Your code here
        inorder(root);
        int n = v.size();
        return v[n-K];
        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
