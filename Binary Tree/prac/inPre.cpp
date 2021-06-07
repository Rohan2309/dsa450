/*


give them idx 0-n in pre
pick ele from pre and create node (where idx is at (0))
search element's pos in inorder -> name it pos
idx++
in inorder 0-pos-1 -> call to build l sub tree of current node
pos+1 to n for right
join l and r sub tree with node
return  node

 
      preorder       Inorder 
     1 2 4 3 5      4 2 1 5 3
idx=0              st      end

idx = 0 -> value 1
1 is at pos 2 at inorder -> curr
make a node -> 1
left of curr is left sub tree's part and right of curr is right sub tree's part
4 , 2 left and 5 , 3 right

now idx = 1 -> value 2
2 is at pos 1 at inorder (search only at left)
make a node -> 2 -> curr
curr-> left will b at left of tree
element 4 , idx++
4 create at tree

now consider right of 1 sub tree
idx3->3 -> find 3 in inorder -> left is 5 add them in tree
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
    return -1;
}

Node *buildtree(int preorder[], int inorder[], int start, int end) //start and end of inorder
{
    static int idx = 0; //pointer in preorder
    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);
    if (start == end) //only one element in inorder (no left and right child)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);               //find pos of idx in inorder
    node->left = buildtree(preorder, inorder, start, pos - 1); //comes first in pre
    node->right = buildtree(preorder, inorder, pos + 1, end);
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
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    Node *root = buildtree(preorder, inorder, 0, 4);
    inorderPrint(root);
    return 0;
}