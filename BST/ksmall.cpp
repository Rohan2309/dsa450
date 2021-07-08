/*
k-th smallest element in BST

Given a BST and an integer K. Find the Kth Smallest element in the BST. 
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

int ans; //global variable

void solve(Node *root, int k, int &idx)
{
    if (!root)
    { //base cond.
        return;
    }
    solve(root->left, k, idx); //left rec for inorder traversal
    if (k == idx)              //if index matches k
    {
        ans = root->data;
        idx++;
        return;
    }
    else
    {
        idx++;
    }
    solve(root->right, k, idx); //right rec for inorder traversal
}

int KthSmallestElement(Node *root, int K)
{
    //add code here.
    int idx = 1; //counter
    ans = -1;    //initially
    solve(root, K, idx);
    return ans;
}

int main()
{

    struct Node *root = new Node(4); //node pointer called root -> it will point towards a new node 1
    root->left = new Node(2);        //root left will point towards a new node 2
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    int k = 3; //to find kth smallest element
    cout << KthSmallestElement(root, k) << endl;
    return 0;
}