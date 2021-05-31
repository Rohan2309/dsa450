/*
Kth smallest element
*PARTITION ALGORITHM*
from quick sort

p is pivot element
{10, 1, 7, 2, 35, 11, 14}; //10 is pivot element
element left to p is less than p and right to p is greater than p
we get (1,7,2,  10   ,25,11,14)
as position of pivot is 4 but value of k is 3
so we apply partition on left side
1,   7,2 
position of pivot is 1 and k is 3
we got right side and pivot element is 7
2,  7  position of 7 is 3 == k
terminates
*/

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // taking the last element as pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int kthSmallest(int arr[], int l, int r, int k) //l is initial location of array and r is end
{
    if (l == r) //pnly one element is present
    {
        if (l == k) //that element is equal to k
        {
            return arr[l]; //return that element
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int p = partition(arr, l, r); //pivot element
        if (p == k)
        {
            return p; //value found
        }
        else if (p < k) //as position of pivot is smaller than k
        {
            return kthSmallest(arr, p + 1, r, k); //right side of the pivot (as it contains greater values)
        }
        else //as position of pivot is greater than k
        {
            return kthSmallest(arr, l, p - 1, k); //left of  pivot
        }
    }
}

int main()
{
    int arr[] = {10, 1, 7, 2, 35, 11, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; //7 is 3rd smallest element (from example)
    int p = 0, q = n - 1;
    cout << kthSmallest(arr, p, q, k) << endl;
    return 0;
}