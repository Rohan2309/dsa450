/*
Count the Reversals 

Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
â€‹Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
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
    int countRev(string s)
    {
        int ans;
        int n = s.length();
        if (n % 2 != 0)
        {              //base case
            return -1; //odd number of brackets
        }

        // if(n&1){  (last bit is setbit only in odd digits)
        // 	return -1;
        // }
        else
        {
            stack<char> st;
            int c = 0;  //closing bracket
            int c2 = 0; //opening bracket
            for (int i = 0; i < n; i++)
            {
                char ch = s[i]; //take char in ch
                if (ch == '{')
                {
                    st.push(ch);
                    c2++;
                }
                else if (ch == '}' and !st.empty() and st.top() == '{')
                {
                    st.pop();
                    c2--; //as already balaced
                }
                else
                { //start with close bracket
                    c++;
                }
            }
            if (c & 1)
            { //if c is odd
                c = (c / 2) + 1;
            }
            else
            {
                c = c / 2;
            }
            if (c2 & 1)
            { //if c is odd
                c2 = (c2 / 2) + 1;
            }
            else
            {
                c2 = c2 / 2;
            }
            ans = c + c2;
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
    w(t)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countRev(s) << "\n";
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