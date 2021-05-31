/*
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.
*/

#include <bits/stdc++.h>
using namespace std;

int soln(int a[], int n)
{
    int sum = 0, flag = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        if (sum == 0 or m[sum] or a[i] == 0)
        {
            flag = 1;
            break;
        }
        else
        {
            m[sum] = 1;
        }
    }
    if (flag == 1)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
int main()
{
    int n, arr[10];
    cout << "enter total no of elements in arr" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter value of element " << i + 1 << endl;
        cin >> arr[i];
    }
    int ans = soln(arr, n);
    cout << ans << endl;

    return 0;
}