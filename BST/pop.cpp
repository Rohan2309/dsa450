/*
Populate Inorder Successor for all nodes

Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
void solve(Node *root, Node *&prev)
{
    if (!root)
    {
        return;
    }
    solve(root->left, prev); //rec for left in inorder trav
    if (prev != NULL)
    {
        prev->next = root; // next pointer will be pointing to inorder succesor
    }
    prev = root;              //root is new prev
    solve(root->right, prev); //rec for right in inorder trav
}
void populateNext(Node *root)
{
    //code here
    Node *prev = NULL;
    solve(root, prev);
}
int main()
{

    return 0;
}