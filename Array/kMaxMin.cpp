/*
Find the Kth max and min element of an array
*/
#include <bits/stdc++.h>
using namespace std;

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
    sort(arr, arr + n);
    int k;
    cout << "enter value of k" << endl;
    cin >> k;
    cout << "kth smallest element is: " << arr[k - 1] << endl;
    sort(arr, arr + n, greater<int>());
    cout << "kth largest element is: " << arr[k - 1] << endl;
    return 0;
}