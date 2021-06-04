/*
Value equal to index value 

Given an array Arr of N positive integers. Your task is to find the elements whose value is equal to that of its index value.

Example 1:

Input: 
N = 5
Arr[] = {15, 2, 45, 12, 7}
Output: 2
Explanation: Only Arr[2] = 2 exists here.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> valueEqualToIndex(int arr[], int n)
{
    // code here
    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
        {
            vect.push_back(i + 1);
        }
    }
    return vect;
}

int main()
{
    int Arr[] = {15, 2, 45, 12, 7}, N = 5;
    auto ans = valueEqualToIndex(Arr, N);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}