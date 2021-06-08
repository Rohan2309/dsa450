
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

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int, int> m;            //height and value {-2,-1,0,1,2}
        queue<pair<Node *, int>> q; //node and height
        if (!root)
        {
            return ans;
        }
        q.push({root, 0}); //root with height 0
        while (!q.empty())
        {
            Node *t = q.front().first; //getting node val
            int h = q.front().second;  //getting height
            q.pop();
            if (!m[h])
            {                   //first time visiting
                m[h] = t->data; //pushing node value
            }
            if (t->left)
            { //if left exists
                q.push({t->left, h - 1});
            }
            if (t->right)
            {
                q.push({t->right, h + 1});
            }
        }
        for (auto x : m)
        {
            ans.push_back(x.second); //will be pushed to ans vector in sorted order(according to key)
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
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    Solution ob;
    vector<int> vec = ob.topView(root);
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}