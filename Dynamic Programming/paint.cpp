/*
Painting the Fence

Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.

Example 1:

Input:
N=2,  K=4
Output: 16
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countWays(int n, int k)
    {
        // code here
        long long mod = 1000000007;
        if (n == 0)
        { // no fence
            return 0;
        }
        if (n == 1) //1 fence
        {
            return k; // no of ways will only be k
        }
        //for n = 2
        long long same = k % mod;             //when same color
        long long diff = (k * (k - 1)) % mod; //when different color
        //from n = 3
        for (long long i = 3; i <= n; i++)
        {
            long long prev = diff % mod; //storing diff in prev
            diff = ((same + diff) * (k - 1)) % mod;
            same = prev % mod;
        }
        return (same + diff) % mod;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    Solution ob;
    cout << ob.countWays(n, k) << endl;

    return 0;
}