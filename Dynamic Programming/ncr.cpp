/*
nCr 

Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

Example 1:

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 

Example 2:

Input: n = 2, r = 4
Output: 0
Explaination: r is greater than n.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //nCr = n!/r! * (n-r)!
    int nCr(int n, int r)
    {
        // code here
        if (n < r) // n can't be smaller than r
        {
            return 0;
        }

        if ((n - r) < r) //taking smaller value
        {
            r = n - r; //as nCr == nC(n-r) || taking 3C0 instead of 3C3
        }
        int mod = 1000000007; //(10^9 + 7)

        int dp[r + 1];
        memset(dp, 0, sizeof(dp)); //setting initial value of arr elements as 0
        dp[0] = 1;                 //start element will be 1 acc. to pascal's triangle

        for (int i = 1; i <= n; i++) //started from 1 as 0 is already formed
        {
            for (int j = min(r, i); j > 0; j--) //min for that barrier  and j>0 so first arr element remains 1
            {
                dp[j] = (dp[j] + dp[j - 1]) % mod; //forming pascal triangle
            }
        }
        return dp[r];
    }
};

int main()
{
    int n, r;
    cin >> n >> r;
    Solution ob;
    cout << ob.nCr(n, r) << endl;

    return 0;
}