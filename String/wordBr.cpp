/*

Word Break

Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 


Example 1:

Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilike"
Output: 1
Explanation:The string can be segmented as "i like".

â€‹Example 2:

Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilikesamsung"
Output: 1
Explanation: The string can be segmented as 
"i like samsung" or "i like sam sung".
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

class Solution
{
public:
    unordered_map<string, int> dp; //dp in map (by default int is 0 in map)
                                   //if we get the word in b array then ans will be 1 otherwise -1

    int solve(string s, vector<string> &b)
    {
        int size = s.length();
        int bsize = b.size();
        int i, j;
        if (size == 0)
        { //we found the whole string
            return 1;
        }
        if (dp[s] != 0)
        {
            return dp[s];
        }

        fo1(i, size)
        { //check every sub string in s is present in b or not
            int f = 0;
            string ss = s.substr(0, i); //taking out substring for every element
            fo(j, bsize)
            { //searching every element in b array
                if (ss.compare(b[j]) == 0)
                { //if substring is found in b array
                    f = 1;
                    break;
                }
            }
            if (f == 1 and solve(s.substr(i, size - i), b) == 1)
            { //if abc is found we send recursive func
                return dp[s] = 1;
            }
        }
        return dp[s] = -1; //if we haven't found
    }

    int wordBreak(string A, vector<string> &B)
    {
        //code here

        int x = solve(A, B);
        if (x == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
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
        int n, i;
        cin >> n;
        vector<string> v;
        fo(i, n)
        {
            string s;
            cin >> s;
            v.pb(s);
        }
        string a;
        cin >> a;
        Solution ob;
        cout << ob.wordBreak(a, v) << "\n";
    }

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

    return 0;
}