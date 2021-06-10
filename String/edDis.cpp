/*
Edit Distance 
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

Insert
Remove
Replace
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.
Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.


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

class Solution
{
public:
    int dp[1001][1001]; //2d dp

    int func(string s, string t, int m, int n)
    {

        //first m is at k of geek
        //and n is at k of gesek
        if (m == -1)
        {                 //if m came to first after g of geek and n is at middle
            return n + 1; //only insert operation
        }
        if (n == -1)
        {                 //extra left in m
            return m + 1; //remove extra in m
        }

        if (dp[m][n] != -1)
        { //already present
            return dp[m][n];
        }
        if (s[m] == t[n])
        { //if same
            return dp[m][n] = func(s, t, m - 1, n - 1);
        }

        //if not same
        int a = func(s, t, m - 1, n - 1); //replace
        int b = func(s, t, m, n - 1);     //insert
        int c = func(s, t, m - 1, n);     //remove

        return dp[m][n] = 1 + min(a, min(b, c));
    }

    int editDistance(string s, string t)
    {
        // Code here
        memset(dp, -1, sizeof(dp)); //every element is set to -1
        int m = s.length();
        int n = t.length();
        return func(s, t, m - 1, n - 1); //-1 for 0 based idx
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
    w(t)
    {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        // for (auto i : ans) {
        // 	cout << i << " ";
        // }
        cout << ans << "\n";
    }

    return 0;
}