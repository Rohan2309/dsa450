/*
Convert a normal BST to Balanced BST
balanced - right and left sub tree diff can be max 1
Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has minimum possible height.
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

vector<Node *> inOrder;         //vector storing inorder traversal of unbalanced
int start = 0;                  //start index
int n = inOrder.size();         //end index
void inorder(struct Node *root) //func for taking out inorder traversal
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    inOrder.push_back(root);
    inorder(root->right);
}

Node *solve(int start, int end)
{ //func for making tree balanced
    if (start > end)
    { //base case
        return NULL;
    }
    int mid = (start + end) / 2;        //middle element find out from vector storing inorder trav
    Node *root = inOrder[mid];          //middle element is root node
    root->left = solve(start, mid - 1); //left rec
    root->right = solve(mid + 1, end);  //right rec
    return root;
}
int main()
{

    struct Node *root = new Node(1); //node pointer called root -> it will point towards a new node 1
    root->left = new Node(2);        //root left will point towards a new node 2
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    inorder(root);
    solve(start, n);
    return 0;
}