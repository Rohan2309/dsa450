/*
Maximum subsequence sum such that no three are consecutive

Given a sequence of positive numbers, find the maximum sum that can be formed which has no three consecutive elements present.
Examples : 

Input: arr[] = {1, 2, 3}
Output: 5
We can't take three of them, so answer is
2 + 3 = 5

Input: arr[] = {3000, 2000, 1000, 3, 10}
Output: 5013 
3000 + 2000 + 3 + 10 = 5013

Input: arr[] = {100, 1000, 100, 1000, 1}
Output: 2101
100 + 1000 + 1000 + 1 = 2101

Input: arr[] = {1, 1, 1, 1, 1}
Output: 4

Input: arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
Output: 27
*/

#include <bits/stdc++.h>
using namespace std;

int a[] = {100, 1000, 100, 1000, 1};
int dp[1000];
int func(int n)
{
    if (n == -1) //base case
    {
        return 0; //array ended
    }
    if (n == 0) //if only 1 element
    {
        return a[0]; //return that element
    }
    if (n == 1) //if only 2 elements
    {
        return a[0] + a[1]; //return sum of 1st and 2nd element
    }
    if (dp[n] != -1) //memnoisation
    {
        return dp[n];
    }

    return dp[n] = max(max(func(n - 1), a[n] + func(n - 2)), a[n] + a[n - 1] + func(n - 3));

    //func(n-1) : not taking current value sending it 1 prev
    //a[n] + func(n - 2) : taking current value and send 2 prev (not taking 1 prev)
    //a[n] + a[n - 1] + func(n - 3) : taking current element rtaking prev element and skipping 2nd prev and sending 3 prev
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    func(n - 1); //from last element of array
    return 0;
}