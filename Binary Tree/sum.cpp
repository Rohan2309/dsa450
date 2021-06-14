/*
Transform to Sum Tree 

Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
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

    int solve(Node *root)
    {
        if (!root)
        {
            return 0; //if not exists then 0 (left or right node)
        }
        int a = solve(root->left);
        int b = solve(root->right);
        int x = root->data; //storing already as we are going to update later
        root->data = a + b;
        return a + b + x;
    }

    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
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

    ob.toSumTree(root);
    ob.inorder(root);

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
    // vi diagonalNode = ob.printBoundary(root);
    // for (int i = 0; i < diagonalNode.size(); i++) {
    // 	cout << diagonalNode[i] << " ";
    // 	cout << endl;
    // }

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