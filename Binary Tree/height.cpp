/*
Height of Binary Tree 

Given a binary tree, find its height.


Example 1:

Input:
     1
    /  \
   2    3
Output: 2
Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   

Your Task:
You don't need to read input or print anything. Your task is to complete the function height() which takes root node of the tree as input parameter and returns an integer denoting the height of the tree. If the tree is empty, return 0. 


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


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
    left = right = NULL; //initially
  }
};

int height(Node *root)
{
  if (!root)
  {
    return 0;
  }
  int x = height(root->left);
  int y = height(root->right);
  return (max(x, y) + 1); //+1 for root node
}

int main()
{
  struct Node *root = new Node(10); //node pointer called root -> it will point towards a new node 1
  root->left = new Node(20);        //root left will point towards a new node 2
  root->right = new Node(30);
  root->left->left = new Node(40);
  root->left->right = new Node(60);
  // root->right->left = new Node(6);
  // root->right->right = new Node(7);
  cout << height(root) << endl;
  return 0;
}