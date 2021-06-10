/*
All suubsequence of a string
*/

#include <bits/stdc++.h>
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
class Solution
{
public:
    void func(string t, int idx, int n, string s)
    { //rec function
        if (idx == n)
        { //base case (when we reach the end we got atleast one subsequence stored in t)
            cout << t << endl;
        }
        else
        {                           //characters left
            func(t, idx + 1, n, s); //didn't include element
            t = t + s[idx];         //include element
            func(t, idx + 1, n, s);
        }
    }

    void subsequence(string s)
    {
        func("", 0, s.length(), s);
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
    string str;
    cin >> str;

    Solution ob;
    ob.subsequence(str);

    return 0;
}