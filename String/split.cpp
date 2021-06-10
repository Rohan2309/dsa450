/*
Split the binary string into substrings with equal number of 0s and 1s

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
    int count(string s)
    {
        // Code here there
        int n = s.length();
        int x = 0; //count of 0
        int y = 0; //count of 1
        int c = 0; //total count
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                x++;
            }
            else
            {
                y++;
            }
            if (x == y)
            {
                c++;
            }
        }
        if (x != y)
        {
            return -1; //no cases
        }
        else
        {
            return c;
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
        string S;
        cin >> S;
        Solution ob;
        int ans = ob.count(S);
        // for (auto i : ans) {
        // 	cout << i << " ";
        // }
        cout << ans << endl;
    }

    return 0;
}