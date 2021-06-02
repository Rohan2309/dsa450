/*
To find unique number in an array where all numbers except one, are present twice
*/

#include <bits/stdc++.h>
using namespace std;

int uni(int a[], int n)
{
    int Xor = a[0];
    for (int i = 1; i < n; i++) //getting xor of all numbers
    {
        Xor = Xor ^ a[i];
    }
    return Xor;
}

int main()
{
    int arr[] = {2, 4, 6, 3, 4, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << uni(arr, n) << endl;
    return 0;
}