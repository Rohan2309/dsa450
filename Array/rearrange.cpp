/*
Rearrange array in alternating positive & negative items with O(1) extra space | Set 1
*/

#include <bits/stdc++.h>
using namespace std;

int soln(int a[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        /* code */
        if (a[i] < 0 and a[j] > 0) //false condition
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        else if (a[i] > 0 and a[j] < 0) //true condition
        {
            i++;
            j++;
        }
        else if (a[i] > 0)
        {
            i++;
        }
        else if (a[j] < 0)
        {
            j--;
        }
    }
    if (i == 0 or i == n)
    {
        for (int i = 0; i < n; i++) //if array contains only negative or only positive elements
        {
            cout << a[i] << " ";
            cout << endl;
        }
    }
    else
    {
        int k = 0;
        while (k < n and i < n)
        {
            swap(a[k], a[i]);
            k = k + 2;
            i++;
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
            cout << endl;
        }
    }
}
int main()
{
    int n, arr[10];
    cout << "enter total no of elements in arr1" << endl;
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