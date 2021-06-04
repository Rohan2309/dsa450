/*
First and last occurrences of x

Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find 
indexes of first and last occurrences of an element x in the given array.

Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
Explanation: First occurrence of 5 is at index 2 and last
             occurrence of 5 is at index 5.

process 1
lower_bound(a,a+n,x)-a //-a so that we get index otherwise we get iterator(idx1)
upper_bound(a,a+n,x)-a-1
idx1 == n then -1
*/

#include <bits/stdc++.h>
using namespace std;

int find(int a[], int n, int x, int togg)
{

    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] < x)
        {
            low = mid + 1;
        }
        else if (a[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            if (togg = -1)
            {
                high = mid + togg; //first index
            }
            else
            {
                low = mid + togg; //last index
            }
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 3, 5, 5, 5, 5, 7, 123, 125};
    int n = 9, x = 7;
    int idx1 = find(arr, n, x, -1); //first occurence
    int idx2 = find(arr, n, x, 1);  //last occurence
    if (idx1 == -1)
    {
        cout << "-1\n";
    }
    else
    {
        cout << idx1 << " " << idx2 << endl;
    }
    return 0;
}