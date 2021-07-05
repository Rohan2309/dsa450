/*
Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
*/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;  //pointer pointing towards left child
    struct TreeNode *right; //pointer for right child

    TreeNode(int val) //constructor taking data
    {
        val = val;
        left = NULL; //initially
        right = NULL;
    }
};
static TreeNode *insucc(TreeNode *root)
{
    TreeNode *p = root->right;
    while (p->left)
    {
        p = p->left;
    }
    return p;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
    { //base case
        return NULL;
    }
    if (key > root->val)
    {                                               //if key is greater than node then go to right
        root->right = deleteNode(root->right, key); //store reccursive call in root -> right
    }
    else if (key < root->val)
    {                                             //if key is smaller than node then go to left
        root->left = deleteNode(root->left, key); //store reccursive call in root -> left
    }
    else
    { //we got the key

        //delete leaf node(example -7)

        //node with only left or right (example - 6)

        if (!root->right)
        {                                //right doesn't exists but left can exist
            TreeNode *temp = root->left; //if left not there then it will store null
            delete (root);
            return temp; //will connect the left node
        }
        else if (!root->left)
        { //left doesn't exists but right can exist
            TreeNode *temp = root->right;
            delete (root);
            return temp;
        }
        //if both exists (eg- 5,3) {successor or predecessor takes place of key}
        else
        {
            TreeNode *temp = insucc(root);              //got inorder successor
            swap(root->val, temp->val);                 //swapping data
            root->right = deleteNode(root->right, key); //delete root
        }
    }
    return root;
}
int main()
{

    return 0;
}