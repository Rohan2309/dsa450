/*
Given two sorted arrays arr1[] of size N and arr2[] of size M.
Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing
order without using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap)
{
    if (gap <= 1)
    {
        return 0;
    }
    else
    {
        int newGap = (gap / 2) + (gap % 2);
        return newGap;
    }
}

void merge(int arr1[], int arr2[], int n, int m)
{
    int gap = n + m, i, j;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (i = 0; i + gap < n; i++)
        { // comparing elements in the first array.
            if (arr1[i] > arr1[i + gap])
            {
                swap(arr1[i], arr1[i + gap]);
            }
        }
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
        { // comparing elements in both arrays.
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
            }
        }
        if (j < m)
        { //comparing elements in second array
            for (j = 0; j + gap < m; j++)
            {
                if (arr2[j] > arr2[j + gap])
                {
                    swap(arr2[j], arr2[j + gap]);
                }
            }
        }
    }
}
int main()
{
    int n, arr1[10], m, arr2[10];
    cout << "enter total no of elements in arr1" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter value of element " << i + 1 << endl;
        cin >> arr1[i];
    }
    cout << "enter total no of elements in arr2" << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "enter value of element " << i + 1 << endl;
        cin >> arr2[i];
    }
    merge(arr1, arr2, n, m);
    cout << " First array" << endl;
    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    cout << " Second array" << endl;
    for (int i = 0; i < m; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    return 0;
}