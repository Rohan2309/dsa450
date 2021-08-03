/*
Maximum product subset of an array
Difficulty Level : Easy
Last Updated : 18 Jun, 2021
Given an array a, we have to find maximum product possible with the subset of elements present in the array. The maximum product can be single element also.
Examples: 

Input: a[] = { -1, -1, -2, 4, 3 }
Output: 24
Explanation : Maximum product will be ( -2 * -1 * 4 * 3 ) = 24

Input: a[] = { -1, 0 }
Output: 0
Explanation: 0(single element) is maximum product possible
 
Input: a[] = { 0, 0, 0 }
Output: 0
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
    int i, n;
    cin >> n;
    int a[n];
    fo(i, n) cin >> a[i];

    int zro_cnt = 0; //counter for 0
    int ng_cnt = 0;  //for neg values
    int pro = 1;
    int maxNeg = INT_MIN; //cases for odd number of negs (remove min neg value)

    fo(i, n)
    {
        if (a[i] == 0)
        {
            zro_cnt++;
            continue;
        }
        if (a[i] < 0)
        {
            ng_cnt++;
            maxNeg = max(maxNeg, a[i]); //storing biggest in negative number
        }
        pro *= a[i]; //product of neg and pos elements except 0
    }
    //edge cases
    if (zro_cnt == n)
    {
        cout << "0";
        return 0;
    }

    else if (ng_cnt == 1 and zro_cnt + ng_cnt == n) //when there is only 1 neg element and all 0 then ans 0
    {
        cout << "0";
        return 0;
    }
    else if (ng_cnt & 1) //if odd number of negative items then we divide the largest neg items from product
    {
        pro /= maxNeg;
    }
    cout << pro;

    return 0;
}