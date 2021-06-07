/*
Reverse Level order traversal
Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:

Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
Example 2:

Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10

Your Task: 
You dont need to read input or print anything. Complete the function reverseLevelOrder() which takes the root of the tree as input parameter and returns a list containing the reverse level order traversal of the given tree.


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
class Solution
{
public:
    vector<int> reverselevelOrder(Node *root)
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
            if (t->right)
            { //right first (for reverse)
                q.push(t->right);
            }
            if (t->left)
            { //if exists
                q.push(t->left);
            }
            q.pop(); //current element
        }
        reverse(ans.begin(), ans.end());
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
    vector<int> res = ob.reverselevelOrder(root);
    for (int i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}