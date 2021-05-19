/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the 
inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
*/

#include <bits/stdc++.h>
using namespace std;

long long merge(int arr[], int l, int mid, int r)
{
    long long inversion = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid; // r -(mid+1) +1
    int a[10], b[10];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];       //a[i]>b[j] and i<j therefore inversion
            inversion += n1 - i; // remaining elements in array a (contribution will be added)
            k++;                 //a[i], a[i+1], a[i+2],.... > b[j]
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    return inversion;
}

long long mergeSort(int arr[], int l, int r)
{
    long long inversion = 0;
    if (r > l)
    {
        int mid = (l + r) / 2;
        inversion += mergeSort(arr, l, mid);
        inversion += mergeSort(arr, mid + 1, r);
        inversion += merge(arr, l, mid, r);
    }
}

int main()
{
    int n, arr[10];
    cout << "enter total no of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << mergeSort(arr, 0, n - 1);
    return 0;
}