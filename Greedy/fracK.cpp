/*
Fractional Knapsack 
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 
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
struct Item
{
    int value;
    int weight;
};
class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, int>> v; //ratio in double and index in int
        //sort desc order value by weight ration
        //then sum will be maximum
        for (int i = 0; i < n; i++)
        {
            double x = (arr[i].value * 1.0) / (arr[i].weight * 1.0); //1.0 as it will convert to double
            v.push_back({x, i});
        }
        sort(v.begin(), v.end(), greater<pair<double, int>>()); // sort in desc order
        int s = 0;                                              //adding weight
        double ans = 0;                                         //storing max answer
        for (int i = 0; i < v.size(); i++)
        {
            if (s + arr[v[i].second].weight < W) // checking if lesser than max weight
            {
                ans += arr[v[i].second].value;
                s += arr[v[i].second].weight;
            }
            else //when greater we will take part of it
            {
                double x = (W - s) * 1.0;
                ans += (x * v[i].first); // v[i].first is already values by weight ratio
                break;
            }
        }
        return ans;
    }
};
int main()
{
    int i, n, w;
    cin >> n >> w;
    Item a[n];
    fo(i, n)
    {
        cin >> a[i].value >> a[i].weight;
    }
    Solution ob;
    cout << ob.fractionalKnapsack(w, a, n) << endl;
    return 0;
}