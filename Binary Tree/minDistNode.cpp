/*
Min distance between two given nodes of a Binary Tree 
Medium Accuracy: 45.05% Submissions: 46075 Points: 4
Given a binary tree and two node values your task is to find the minimum distance between them.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 
*/

#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
// #define int             long long
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
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

#define vi vector<int>
#define vvi vector<vi>

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
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node *lca(Node *root, int n1, int n2)
    {
        //Your code here
        if (!root)
        {
            return NULL;
        }
        if (root->data == n1 or root->data == n2)
        {
            return root;
        }
        Node *l = lca(root->left, n1, n2);
        Node *r = lca(root->right, n1, n2);
        if (l and r)
        {
            return root;
        }
        if (l)
        {
            return l;
        }
        else
        {
            return r;
        }
    }
    int solve(Node *root, int val)
    {
        if (!root)
        {
            return 0;
        }
        if (root->data == val)
        {
            return 1;
        }
        int a = solve(root->left, val);
        int b = solve(root->right, val);
        if (!a and !b)
        {
            return 0;
        }
        else
        {
            return a + b + 1;
        }
    }
    int findDist(Node *root, int a, int b)
    {
        // Your code here
        Node *LCA = lca(root, a, b); //find lca
        int x = solve(LCA, a);       //dist from lca to a
        int y = solve(LCA, b);
        return x + y - 2;
    }
};
int main()
{

    return 0;
}