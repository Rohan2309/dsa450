/*
Lowest Common Ancestor in a BST
Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
Node *LCA(Node *root, int n1, int n2)
{
    //Your code here
    if (!root)
    { //base case
        return NULL;
    }
    //both are smaller then go to left
    if (n1 < root->data and n2 < root->data)
    {
        return LCA(root->left, n1, n2);
    }
    //both are greater then go to right
    else if (n1 > root->data and n2 > root->data)
    {
        return LCA(root->right, n1, n2);
    }
    else
        return root;
}
int main()
{

    return 0;
}