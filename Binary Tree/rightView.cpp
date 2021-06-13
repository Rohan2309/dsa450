/*
Right View of Binary Tree 
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:

Input:
       1
    /    \
   3      2
Output: 1 2
Example 2:

Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
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

class Solution
{
public:
    vector<int> rightView(Node *root)
    {
        // Your code here
        vector<int> ans;
        queue<Node *> q; //queue of type node
        if (!root)
        { //base case
            return ans;
        }
        q.push(root); //pushing root
        while (!q.empty())
        {
            int l = q.size(); //get nodes in current level
            Node *t;
            while (l--)
            {
                t = q.front(); //take out first node from q in t
                q.pop();
                if (t->left)
                { //if left present push in q
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }
            ans.push_back(t->data); //pushing last element in ans vec
        }
        return ans;
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
    vector<int> vec = ob.rightView(root);
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}