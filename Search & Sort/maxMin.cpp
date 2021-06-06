/*
Maximum and minimum of an array using minimum number of comparisons
*/

#include <bits/stdc++.h>
using namespace std;

struct Pair //will return two values from function
{
    int min;
    int max;
};

struct Pair getMinMax(int a[], int n)
{
    struct Pair minmax;
    int i;
    if (n == 1) //if there is only 1 element present
    {
        minmax.min = a[0];
        minmax.max = a[0];
        return minmax;
    }

    if (a[0] > a[1]) //more than 1 element present
    {
        minmax.min = a[1];
        minmax.max = a[0];
    }
    else
    {
        minmax.min = a[0];
        minmax.max = a[1];
    }

    for (i = 2; i < n; i++)
    {
        if (a[i] > minmax.max)
        {
            minmax.max = a[i];
        }
        else if (a[i] < minmax.min)
        {
            minmax.min = a[i];
        }
    }
    return minmax;
}

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Pair minmax = getMinMax(arr, n);
    cout << " Min elemement : " << minmax.min << endl;
    cout << " Max elemement : " << minmax.max << endl;
    return 0;
}