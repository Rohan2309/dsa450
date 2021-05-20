/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array 
whose sum is equal to K.
*/

#include <bits/stdc++.h>
using namespace std;

int soln(int arr[], int n, int sum)
{
    int twiceCount = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        twiceCount = twiceCount + m[sum - arr[i]];
        if (sum - arr[i] == arr[i])
        {
            twiceCount--;
        }
    }
    return twiceCount / 2;
}
int main()
{
    int n, arr[10], k;
    cout << "enter total no of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter value of element " << i + 1 << endl;
        cin >> arr[i];
    }
    cout << "Enter value of k";
    cin >> k;
    int ans = soln(arr, n, k);
    cout << ans << endl;
    return 0;
}