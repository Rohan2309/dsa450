/*
Bottom View of Binary Tree 

Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
 
 Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
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
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
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
            m[h] = t->data; //pushing node value (updating)
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
    vector<int> vec = ob.bottomView(root);
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}