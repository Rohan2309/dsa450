/*
maximumimum product subarray
*time O(n)*
*/

#include <bits/stdc++.h>
using namespace std;

long prod(int a[], int n)
{
    long minimum = 1, maximum = 1, res = 1; //res will be final ans
    if (n == 0)                             //base case when no elements in array
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0) //if element is positive
        {
            maximum *= a[i]; //positive will always give max ans
            minimum = min(minimum, minimum * a[i]);
        }
        else if (a[i] == 0) // if value is 0 then reset all values
        {
            maximum = minimum = 1; //resetting
        }
        else //if negative element
        {
            swap(minimum, maximum); //to achieve bigger value
            minimum *= a[i];
            if (1 > a[i] * maximum) // will keep bigger result in max
            {
                maximum = 1;
            }
            else
            {
                maximum = a[i] * maximum;
            }
        }
        res = max(res, maximum);
    }
    return res;
}

int main()
{
    int arr[10] = {6, -3, -10, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << prod(arr, n) << endl;
    return 0;
}