/*
Partition Equal Subset Sum 
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];

    int solve(int n, int a[], int s)
    {
        if (n == -1) //array ends
        {
            if (s == 0) //and sum becomes 0
            {
                return 1; //then yes
            }
            else //if sum not 0
            {
                return 0; //then no
            }
        }
        if (s < 0) //if sum becomes negativ
        {
            return 0; //answer is not possible
        }
        if (s == 0) //valid case
        {
            return 1; //yes
        }
        //memorization
        if (dp[n][s] != -1)
        {
            return dp[n][s];
        }
        return dp[n][s] = solve(n - 1, a, s - a[n]) or solve(n - 1, a, s); //1st time we are subtracting and seeing
        //second time we are not subtracting
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int s = 0;
        for (int i = 0; i < N; i++)
        {
            s += arr[i]; //calculating total sum
        }
        if (s & 1) //if odd
        {
            return 0; //answer not possible
        }
        //if even then there is a chance
        s = s / 2;
        dp[N][s]; //resizing dp
        //n is size of array and s is half of s
        memset(dp, -1, sizeof(dp));
        return solve(N - 1, arr, s); //n-1 as we are accessing from last index
    }
};

int main()
{
    int n, arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    if (ob.equalPartition(n, arr))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}