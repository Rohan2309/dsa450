/*

binary tree can have only 2 child left and right
left will be smaller and right will be larger

max nodes at level n = 2^n 
at root level 0 -> 2^0 = 1
levels 0,1,2

height of tree is total nymber of levels 
max nodes ina a tree of height h is (2^h -1)
heights 1,2,3

for n nodes min possible height or min no of levels are
log2(n+1)

a btree with l leaves has at least log2(n+1)+1 number of leaves (leaves are at end with no child)
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

/*


       1
      / \
     2   3
    /\  / \
   4 5 6   7

pre order traversal
we should write the value of the root
then go to left sub tree
then right sub tree


preorder: 1->2->4->5->3->6->7

in order traversal
left subtree
root
right subtree

inorder : 4->2->5->1->6->3->7

post order traversal
left subtree
right subtree 
root

postorder: 4->5->2->6->7->3->1


*/

void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}