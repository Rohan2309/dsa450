/*
Searching in an array where adjacent differ by at most k

x is the element to search
*/

#include <bits/stdc++.h>
using namespace std;

int soln(int a[], int n, int k, int x)
{

    int i = 0;
    while (i < n)
    {
        if (a[i] == x) //valid ans
        {
            return i;
        }
        //exceptional cases
        i = i + max(1, abs(a[i] - x) / k); //max because it jumps atleast 1 step (a[i]-k == diff/k)
    }
    cout << "Number is not present" << endl;
    return -1;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]); //5
    int x = 6;
    int k = 1;
    int ans = soln(arr, n, k, x);
    cout << ans << endl;

    return 0;
}