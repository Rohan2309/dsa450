/*
Binary Tree to BST 
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void inorder_tree(Node *root, vector<int> &v)
{
    if (!root)
    {
        return;
    }
    inorder_tree(root->left, v);
    v.push_back(root->data); //storing in vector
    inorder_tree(root->right, v);
}
void inorder_bst(Node *root, vector<int> &v, int &i)
{
    if (!root)
    {
        return;
    }
    inorder_bst(root->left, v, i);
    root->data = v[i]; //updating root data
    i++;               //increasing counter
    inorder_bst(root->right, v, i);
}
// The given root is the root of the Binary Tree
// Return the root of the generated BST
Node *binaryTreeToBST(Node *root)
{
    //Your code goes here
    vector<int> v; //to store inorder trav of normal tree
    inorder_tree(root, v);
    sort(v.begin(), v.end()); //sorting as bst's inorder is in sorted order
    int i = 0;                //iterator
    inorder_bst(root, v, i);
    return root;
}

int main()
{

    return 0;
}