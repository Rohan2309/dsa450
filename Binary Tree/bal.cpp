/*
Check for Balanced Tree 

Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 
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
    int f = 1; //true at beggining
    int solve(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        if (abs(l - r) > 1)
        { //abs for cond. like 1-2
            f = 0;
        }
        return max(l, r) + 1;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        f = 1;
        solve(root); //if it gives f=0, then f will be 0 otherwise 1
        return f;
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
    if (ob.isBalanced(root))
    {
        cout << "balanced" << endl;
    }
    else
    {
        cout << "not balanced" << endl;
    }

    //vector/map
    // for (auto i : ans) {
    // 	cout << i << " ";
    // }

    //int
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