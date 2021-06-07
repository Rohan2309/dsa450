/*
Level order traversal

Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.


Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2
Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N

Your Task:
You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
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
    vector<int> levelOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        if (!root)
        { //tree doesn't exist
            return ans;
        }
        queue<Node *> q;
        q.push(root); //pushing root node in q
        while (!q.empty())
        {
            Node *t = q.front();    //storing in node
            ans.push_back(t->data); //storing in ans vect
            if (t->left)
            { //if exists
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
            q.pop(); //current element
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
    vector<int> res = ob.levelOrder(root);
    for (int i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}