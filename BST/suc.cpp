/*
Predecessor and Successor 

There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case, if the either of predecessor or successor is not found print -1.
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left;  //pointer pointing towards left child
    struct Node *right; //pointer for right child

    Node(int val) //constructor taking data
    {
        key = val;
        left = NULL; //initially
        right = NULL;
    }
};
Node *inpre(Node *root)
{
    Node *p = root->left; //storing left in p
    while (p->right)
    { //moving to extreme right
        p = p->right;
    }
    return p;
}

Node *insuc(Node *root)
{
    Node *p = root->right; //storing right in p
    while (p->left)
    { //moving to extreme left
        p = p->left;
    }
    return p;
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    // Your code goes here
    if (!root)
    {
        return;
    }
    if (root->key == key)
    { //if key matches
        if (root->left)
        { //if left exista
            pre = inpre(root);
        }
        if (root->right)
        { //if right exists
            suc = insuc(root);
        }
        return;
    }
    if (key > root->key)
    {               //moving towards right
        pre = root; //updating predecessor as we moving towards right
        findPreSuc(root->right, pre, suc, key);
    }
    else if (key < root->key)
    {               //moving towards left
        suc = root; //updating successor as we moving towards left
        findPreSuc(root->left, pre, suc, key);
    }
}

int main()
{
    return 0;
}