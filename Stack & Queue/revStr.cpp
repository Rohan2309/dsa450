/*
Reverse a string using Stack 
Easy Accuracy: 54.33% Submissions: 38669 Points: 2
You are given a string S, the task is to reverse the string using stack.

 

Example 1:


Input: S="GeeksforGeeks"
Output: skeeGrofskeeG
*/

#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
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

/*
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
*/
char *reverse(char *S, int len)
{
    //code here
    stack<char> st;
    for (int i = 0; i < len; i++)
        st.push(S[i]);
    char *a = new char[len]; //char array
    int i = 0;
    while (!st.empty())
    {
        a[i++] = st.top();
        st.pop();
    }
    a[i] = '\0'; //char array we have to fill null char in char array (compiler understands that string ends)
    return a;
}
int main()
{
    ll int t;
    cin >> t;
    while (t--)
    {
        char str[1000];
        cin >> str;
        ll int len = strlen(str);
        char *ch = reverse(str, len);
        cout << ch;
        cout << endl;
    }
    return 0;
}