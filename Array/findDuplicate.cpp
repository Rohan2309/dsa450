/*

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % n] = arr[arr[i]] + n;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] / n > 1)
        {
            cout << "Duplicate element: " << i << endl;
        }
    }
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
    solve(arr, n);
    return 0;
}