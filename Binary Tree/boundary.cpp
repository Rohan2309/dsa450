/*
Boundary Traversal of binary tree 
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1
      /   \
     2     3    
   
Output: 1 2 3
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>                   //max heap
#define pqs priority_queue<int, vi, greater<int>> //min heap
#define setbits(x) __builtin_popcountll(x)        //gives number of setbits
#define zrobits(x) __builtin_ctzll(x)             //gives number of 0 bits
#define mod 1000000007                            // 1e9+7  ans%mod
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n]; //dynamic array
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)                                                      //test case
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //random shuffle

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //policy based ds

#define deb(x) cout << #x << " " << x << endl; //for debugging
#define fo(i, n) for (i = 0; i < n; i++)
#define fo1(i, n) for (i = 1; i <= n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)

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

class Solution
{
public:
    void LeftTree(Node *root, vector<int> &ans)
    { //& as it will update
        if (!root)
        {
            return;
        }
        if (root->left)
        { //if left exists
            ans.push_back(root->data);
            LeftTree(root->left, ans);
        }
        else if (root->right)
        {
            ans.push_back(root->data);
            LeftTree(root->right, ans);
        }
    }

    void Leaf(Node *root, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }
        Leaf(root->left, ans); //got to full left
        if (!root->left and !root->right)
        {                              //if left and right node is not there then lead
            ans.push_back(root->data); //backstrack
        }
        Leaf(root->right, ans);
    }

    void RightTree(Node *root, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }
        if (root->right)
        {
            RightTree(root->right, ans); //send to right most
            ans.push_back(root->data);   //then push
        }
        else if (root->left)
        {
            RightTree(root->left, ans);
            ans.push_back(root->data);
        }
    }

    vector<int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        ans.push_back(root->data); //pushing root
        LeftTree(root->left, ans);
        Leaf(root, ans);
        RightTree(root->right, ans);
        return ans;
    }
};

void FIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
    FIO();
    struct Node *root = new Node(1); //node pointer called root -> it will point towards a new node 1
    root->left = new Node(2);        //root left will point towards a new node 2
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution ob;
    // w(t) {
    // 	string s; cin >> s;
    // 	Solution ob;
    // 	cout << ob.countRev(s) << "\n";
    // }

    //boolean func
    // if (ob.isBalanced(root)) {
    // 	cout << "balanced" << endl;
    // }
    // else {
    // 	cout << "not balanced" << endl;
    // }

    //vector/map
    vi diagonalNode = ob.printBoundary(root);
    for (int i = 0; i < diagonalNode.size(); i++)
    {
        cout << diagonalNode[i] << " ";
        cout << endl;
    }

    // int
    // cout << a << "\n";

    // vi res = ob.zigZagTraversal(root);
    // int n = res.size();
    // int i;
    // fo(i, n) {
    // 	cout << res[i] << " ";
    // }
    // cout << endl;
    return 0;
}