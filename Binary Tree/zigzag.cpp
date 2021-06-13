/*
ZigZag Tree Traversal 

Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

 

Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
*/

/*


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
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> ans;
        queue<Node *> q;
        if (!root)
        {
            return ans;
        }
        q.push(root);
        int f = 1; //odd even toggler (1=odd)
        while (!q.empty())
        {
            vector<int> temp; //each level elements will be stored
            int sz = q.size();
            while (sz--)
            {
                Node *t = q.front();
                temp.push_back(t->data); //pushing in temp vec
                q.pop();
                if (t->left)
                { //if left present
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }
            if (f % 2 == 0)
            {
                reverse(temp.begin(), temp.end()); //if even (for zigzag)
            }
            int n = temp.size();
            for (int i = 0; i < n; i++)
            { //storing in final ans
                ans.push_back(temp[i]);
            }
            f = !f; //f value willbe changed
        }
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
    // w(t) {
    // 	string s; cin >> s;
    // 	Solution ob;
    // 	cout << ob.countRev(s) << "\n";
    // }

    //boolean func
    // if (ob.ispar(a)) {
    // 	cout << "balanced" << endl;
    // }
    // else {
    // 	cout << "not balanced" << endl;
    // }

    //vector/map
    // for (auto i : ans) {
    // 	cout << i << " ";
    // }

    //int
    // cout << a << "\n";
    struct Node *root = new Node(1); //node pointer called root -> it will point towards a new node 1
    root->left = new Node(2);        //root left will point towards a new node 2
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution ob;
    vi res = ob.zigZagTraversal(root);
    int n = res.size();
    int i;
    fo(i, n)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}