/*
Isomorphic Strings 

Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

Example 1:

Input:
str1 = aab
str2 = xxy
Output: 1
Explanation: There are two different
charactersin aab and xxy, i.e a and b
with frequency 2and 1 respectively.
Example 2:

Input:
str1 = aab
str2 = xyz
Output:
Explanation: There are two different
charactersin aab but there are three
different charactersin xyz. So there
won't be one to one mapping between
str1 and str2.



                   m1          m2
s1= abaab        a : x       x : a
s2= xyxyy        b : y       y : b

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
    bool areIsomorphic(string s1, string s2)
    {

        // Your code here
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 != n2)
        { //length isn't same
            return false;
        }
        int m1[256] = {0}; //char array
        int m2[256] = {0};
        for (int i = 0; i < n1; i++) //itr  through first loop
        {
            // For string to be isomorphic the previous counts
            // of appearences of
            // current character in both string must be same if
            // it is not same we return false.
            m1[s1[i]]++;
            m2[s2[i]]++;
            if (m1[s1[i]] != m2[s2[i]])
            {
                return false;
            }
        }
        return true;
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
        cin >> s2;
        Solution ob;
        cout << ob.areIsomorphic(s1, s2) << endl;
    }
    return 0;
}