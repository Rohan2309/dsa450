/*
Find the Kth max and min element of an array
*/
#include <bits/stdc++.h>
using namespace std;

int kSort(int arr[10], int k, int n)
{

    sort(arr, arr + n);

    cout << "kth smallest element is: " << arr[k - 1] << endl;
    sort(arr, arr + n, greater<int>());
    cout << "kth largest element is: " << arr[k - 1] << endl;
}

int main()
{
    int n, arr[10];
    cout << "enter total no of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter value of element " << i + 1 << endl;
        cin >> arr[i];
    }
    int k;
    cout << "enter value of k" << endl;
    cin >> k;
    cout << kSort(arr, k, n) << endl;
    return 0;
}