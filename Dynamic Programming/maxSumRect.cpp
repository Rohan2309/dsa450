/*
Maximum sum Rectangle 
Given a 2D matrix M of dimensions RxC. Find the maximum sum subarray in it.

Example 1:

Input:
R=4
C=5
M=[[1,2,-1,-4,-20],
[-8,-3,4,2,1],
[3,8,10,1,3],
[-4,-1,1,7,-6]]
Output:
29
Explanation:
The matrix is as follows and the
blue rectangle denotes the maximum sum
rectangle.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kadene(vector<int> v, int n)
    {
        int ma = INT_MIN;
        int maxUntil = 0;
        for (int i = 0; i < n; i++)
        {
            maxUntil += v[i];
            if (maxUntil > ma)
            {
                ma = maxUntil;
            }
            if (maxUntil < 0)
            {
                maxUntil = 0;
            }
        }
        return ma;
    }
    int maximumSumRectangle(int r, int c, vector<vector<int>> m)
    {
        // code here
        int ma = INT_MIN;
        for (int i = 0; i < r; i++) //for rows only
        {
            vector<int> ans(c);
            for (int j = i; j < r; j++) //from that rows to all rows
            {
                for (int k = 0; k < c; k++) //for columns
                {
                    ans[k] += m[j][k]; //adding values in ans vect
                }
                ma = max(ma, kadene(ans, c)); //for subarray we are taking column
            }
        }
        return ma;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    Solution ob;
    cout << ob.maximumSumRectangle(n, m, v) << endl;
    return 0;
}