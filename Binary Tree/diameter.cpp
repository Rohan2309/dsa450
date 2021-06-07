/*
Diameter of Binary Tree 
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree.
 The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest
  path are shaded (note that there is more than one path in each tree of length nine, but no path longer
   than nine nodes).

   Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
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
class Solution
{
public:
    int ma; //global var

    int func(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        int x = func(root->left); //max height from left node
        int y = func(root->right);
        ma = max(ma, y + x + 1); //+1 for  node itself
        return (max(x, y) + 1);  //returning height
    }

    //Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        // Your code here
        ma = INT_MIN;
        int x = func(root);
        return ma;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    struct Node *root = new Node(10); //node pointer called root -> it will point towards a new node 1
    root->left = new Node(20);        //root left will point towards a new node 2
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    Solution ob;
    cout << ob.diameter(root) << endl;

    return 0;
}