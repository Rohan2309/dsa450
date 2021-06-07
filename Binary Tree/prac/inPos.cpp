/*
post order root will be at end

give them idx 0-n in post
pick ele from post and create node (where idx is at)
from last element of post (idx)
idx--
search element's pos in inorder -> name it pos
inorder first right then left
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

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i; //return pos
        }
    }
    return -1; //necer reach
}

Node *buildtree(int postorder[], int inorder[], int start, int end) //start and end of inorder
{
    static int idx = 5 - 1; //pointer in post (n-1)
    if (start > end)
    {
        return NULL;
    }

    int curr = postorder[idx];
    idx--;
    Node *node = new Node(curr);
    if (start == end) //only one element in inorder (no left and right child)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);               //find pos of idx in inorder
    node->right = buildtree(postorder, inorder, pos + 1, end); //right is build first at post
    node->left = buildtree(postorder, inorder, start, pos - 1);

    return node;
}

void inorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    int inorder[] = {4, 2, 1, 5, 3};
    int postorder[] = {4, 2, 5, 3, 1};
    Node *root = buildtree(postorder, inorder, 0, 4);
    inorderPrint(root);
    return 0;
}