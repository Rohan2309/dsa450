/*
Merge two BST
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

vector<Node *> inOrder; //vector storing inorder traversal of tree 1
int start = 0;          //start index
int n = inOrder.size(); //end index

vector<Node *> inOrder1; //vector storing inorder traversal of tree 2
int start1 = 0;          //start index
int n1 = inOrder.size(); //end index

vector<Node *> merged;
void inorder(struct Node *root) //func for taking out inorder traversal of tree 1
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    inOrder.push_back(root);
    inorder(root->right);
}
void inorder1(struct Node *root) //func for taking out inorder traversal of tree 2
{
    if (root == NULL)
    {
        return;
    }
    inorder1(root->left);
    inOrder1.push_back(root);
    inorder1(root->right);
}

Node *solve(int start, int end) //func for making tree balanced
{
    if (start > end)
    { //base case
        return NULL;
    }
    int mid = (start + end) / 2;        //middle element find out from vector storing inorder trav
    Node *root = merged[mid];           //middle element is root node
    root->left = solve(start, mid - 1); //left rec
    root->right = solve(mid + 1, end);  //right rec
    return root;
}

int main()
{
    //tree1
    struct Node *root = new Node(3); //node pointer called root -> it will point towards a new node 1
    root->left = new Node(2);        //root left will point towards a new node 2
    root->right = new Node(4);
    root->left->left = new Node(1);
    //tree2
    struct Node *root1 = new Node(6); //node pointer called root -> it will point towards a new node 1
    root1->left = new Node(5);        //root left will point towards a new node 2
    root1->right = new Node(7);
    inorder(root);   //inorder of tree1
    inorder1(root1); //inorder of tree 2

    //merge two sorted vectors

    merge(inOrder.begin(), inOrder.end(), inOrder1.begin(),
          inOrder1.end(), merged.begin());
    int st = 0;
    int en = merged.size();
    //making balanced tree from vect
    solve(start, en);
    return 0;
}