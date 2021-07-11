/*
Maximize The Cut Segments 
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
Example 2:

Input:
N = 5
x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[10001];

    int func(int n, int x, int y, int z)
    {
        if (n == 0) //no available length left
        {
            return 0;
        }
        //memoization
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int op1 = INT_MIN;
        int op2 = INT_MIN;
        int op3 = INT_MIN;

        if (n >= x) //x should be lesser than or equal to available length
        {
            op1 = func(n - x, x, y, z); //n-x is length available
        }
        if (n >= y) //y should be lesser than or equal to available length
        {
            op2 = func(n - y, x, y, z);
        }
        if (n >= z) //z should be lesser than or equal to available length
        {
            op3 = func(n - z, x, y, z);
        }
        return dp[n] = max(op1, max(op2, op3)) + 1; //+1 because current cut
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int m = sizeof(dp);
        memset(dp, -1, m);
        int a = func(n, x, y, z);
        if (a < 0)
        {
            return 0; //answer not possible
        }
        else
        {
            return a;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z;
    Solution ob;
    cout << ob.maximizeTheCuts(n, x, y, z) << endl;

    return 0;
}