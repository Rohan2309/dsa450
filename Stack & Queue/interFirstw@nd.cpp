/*
Interleave the first half of the queue with second half
Difficulty Level : Medium
Last Updated : 06 Nov, 2020
Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

Only a stack can be used as an auxiliary space.

Examples:

Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20
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

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int n = q.size(); //4
    stack<int> s;
    //q has 1 2 3 4
    for (int i = 0; i < n / 2; i++) //half eles to stk from q
    {
        s.push(q.front());
        q.pop();
    }
    //q has 3 4
    //s has 1 2 ( last in first out) (2 is on top)
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    //q has 3 4 2 1
    //we want 2 1 in stk
    for (int i = 0; i < n / 2; i++)
    {
        q.push(q.front());
        q.pop();
    }
    //q has 2 1 3 4
    for (int i = 0; i < n / 2; i++)
    {
        s.push(q.front());
        q.pop();
    }
    //s has 2 1 (1 is on top)
    //q has 3 4 (3 is front)
    while (!s.empty())
    {
        q.push(s.top()); //1 into q
        s.pop();
        q.push(q.front()); //3 into q
        q.pop();
    }
    //we get q as 1 3 2 4

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}