/*
Triplet Sum in Array

Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up 
to the given integer X.
*/

#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int n, int X)
{
    //Your Code Here
    int ans = 0;
    sort(A, A + n);
    int i;                      //first pointer at start
    for (i = 0; i < n - 2; i++) // as triplet so n-2 (third last element)
    {
        int l = i + 1, r = n - 1; //left pointer will be of second value and right pointer for last
        while (l < r)
        {
            if (A[i] + A[l] + A[r] == X)
            {
                ans = 1;
                break;
            }
            else if (A[i] + A[l] + A[r] < X) //if total is smaller than x
            {
                l++; //sorted oder left will increase
            }
            else //if total is larger than x
            {
                r--; //sorted oder right will decrease
            }
        }
        if (ans == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 13;
    cout << find3Numbers(arr, n, x) << endl;
    return 0;
}