/*
Count triplets with sum smaller than X

Given an array arr[] of distinct integers of size N and a sum value X, the task is to find count of 
triplets with the sum smaller than the given sum value X.

 

Example 1:

Input: N = 6, X = 2
arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with 
sum less than 2 (-2, 0, 1) and (-2, 0, 3). 

Example 2:

Input: N = 5, X = 12
arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with 
sum less than 12 (1, 3, 4), (1, 3, 5), 
(1, 3, 7) and (1, 4, 5).

*/

#include <bits/stdc++.h>
using namespace std;

long long find3Numbers(long long A[], long long n, long long X) //x is given value
{
    //Your Code Here
    int c = 0;
    sort(A, A + n);
    int i;                      //1st pointer at start
    for (i = 0; i < n - 2; i++) // as triplet so n-2 (third last element)
    {
        int l = i + 1; //left pointer will be of 2nd value
        int r = n - 1; //right pointer for last element
        while (l < r)
        {
            int sum = A[i] + A[l] + A[r];
            if (sum < X)
            {
                c += (r - l); //all elements from right to left are small
                l++;
            }
            else //if not less
            {
                r--; //shift rightmost element towards left as it will be small
            }
        }
    }
    return c;
}
int main()
{

    long long arr[] = {1, 4, 45, 6, 10, 8};
    long long n = sizeof(arr) / sizeof(arr[0]);
    long long x = 13;
    cout << find3Numbers(arr, n, x) << endl;
    return 0;
}