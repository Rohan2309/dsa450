/*
Check for BST

Given a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;  //pointer pointing towards left child
    struct Node *right; //pointer for right child

    Node(int val) //constructor taking data
    {
        data = val;
        left = NULL; //initially
        right = NULL;
    }
};
void func(Node *root, Node *&prev, int &f)
{
    if (!root)
    { //base case
        return;
    }
    //inorder
    func(root->left, prev, f); //left recc
    //root
    if (prev != NULL and root->data <= prev->data)
    { //false case
        f = 0;
        return;
    }
    prev = root;                //cuurent node will be prev
    func(root->right, prev, f); //right recc
}
//Function to check whether a Binary Tree is BST or not.
bool isBST(Node *root)
{
    //inorder of bst will always be in sorted order
    // Your code here
    int f = 1;
    Node *prev = NULL;
    func(root, prev, f);
    return f;
}
int main()
{

    return 0;
}