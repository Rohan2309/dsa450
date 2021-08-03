/*
Roman Number to Integer 

Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5
Example 2:

Input:
s = III 
Output: 3
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

#define deb(x) cout << #x << " " << x << endl; //for debugging
#define fo(i, n) for (i = 0; i < n; i++)
#define fo1(i, n) for (i = 1; i <= n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)

class Solution
{
public:
    int romanToDecimal(string &str)
    {
        // code here
        int n = str.length();
        map<char, int> m;
        m.insert(pair<char, int>('I', 1));
        m.insert(pair<char, int>('V', 5));
        m.insert(pair<char, int>('X', 10));
        m.insert(pair<char, int>('L', 50));
        m.insert(pair<char, int>('C', 100));
        m.insert(pair<char, int>('D', 500));
        m.insert(pair<char, int>('M', 1000));

        int result = m[str[n - 1]]; //start from last position
        for (int i = n - 2; i >= 0; i--)
        { //start from second last character
            if (m[str[i]] < m[str[i + 1]])
            {
                result -= m[str[i]]; //substraction
            }
            else
            {
                result += m[str[i]]; //addition
            }
        }
        return result;
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
    string s1, s2;
    w(t)
    {
        cin >> s1;
        Solution ob;
        int ans = ob.romanToDecimal(s1);
        cout << ans << endl;
    }

    return 0;
}