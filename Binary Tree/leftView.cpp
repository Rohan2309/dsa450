
/*
Left View of Binary Tree 

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3
*/

/*

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
    vector<int> leftView(Node *root)
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
            int l = q.size();               //get nodes in current level
            ans.push_back(q.front()->data); //taking first ele of q in vec
            while (l--)
            {
                Node *t = q.front(); //take out first node from q in t
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
    vector<int> vec = ob.leftView(root);
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}