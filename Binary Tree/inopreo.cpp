/*
Construct Tree from Inorder & Preorder

Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
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

void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
class Solution
{
public:
    int idx = 0;
    unordered_map<int, int> m;

    Node *solve(int pre[], int in[], int lb, int ub)
    {
        if (lb > ub)
        {
            return NULL;
        }
        Node *res = new Node(pre[idx++]); //every node in preorder
        if (lb == ub)
        { //leaf node (no one in left and right)
            return res;
        }
        int mid = m[res->data]; //when 0 (we will find location of 0 in inorder)
        res->left = solve(pre, in, lb, mid - 1);
        res->right = solve(pre, in, mid + 1, ub);
        return res;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        idx = 0;
        m.clear();
        for (int i = 0; i < n; i++)
        {
            m[in[i]] = i;
        } //inorder values map
        Node *root = solve(pre, in, 0, n - 1);
        return root;
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
    // struct Node *root = new Node(1); //node pointer called root -> it will point towards a new node 1
    // root->left = new Node(2);        //root left will point towards a new node 2
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    int n, i;
    cin >> n;
    int inorder[n], preorder[n];
    fo(i, n)
    {
        cin >> inorder[i];
    }
    fo(i, n)
    {
        cin >> preorder[i];
    }
    Solution ob;

    int inorder[n], preorder[n];
    fo(i, n)
    {
        cin >> inorder[i];
    }
    fo(i, n)
    {
        cin >> preorder[i];
    }
    Node *root = ob.buildTree(inorder, preorder, n);
    postorder(root);

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