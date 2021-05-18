/*
Write an efficient program to find the sum of contiguous subarray within a

one-dimensional array of numbers that has the largest sum. 

(Kadane's Algorithm)
*/

#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n)
{
    int maxSum = 0, currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum = currentSum + arr[i];
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
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
    int max = kadane(arr, n);
    cout << "Maximum contiguous sum is " << max;
    return 0;
}