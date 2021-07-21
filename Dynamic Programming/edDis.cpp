/*
Edit Distance 
Medium Accuracy: 49.98% Submissions: 29327 Points: 4
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
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001]; //2d dp
    int func(string s, string t, int m, int n)
    { //first m is at k of geek
        //and n is at k of gesek
        //base
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

        return dp[m][n] = 1 + min(a, min(b, c)); //1 + becuz we need 1 operation atleast
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

int main()
{
    string s, t;
    cin >> s >> t;
    Solution ob;
    int ans = ob.editDistance(s, t);
    cout << ans << endl;
    return 0;
}