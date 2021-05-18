/*
Given an array arr[] denoting heights of N towers and a positive integer K,
you have to modify the height of each tower either by increasing or decreasing them by K only once. 
After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers after 
you have modified each tower.
*/

#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0]; //last element - first element is max diff currently
    int smallest = arr[0] + k;     //increase the height of the smaller tower
    int largest = arr[n - 1] - k;  //decrease the height of the larger tower
    int minimum, maximum;

    for (int i = 0; i < n; i++)
    {
        minimum = min(smallest, arr[i + 1] - k);
        maximum = max(largest, arr[i] + k);
        if (minimum < 0)
        {
            continue; //exception case
        }
        else
        {
            ans = min(ans, maximum - minimum);
        }
    }
    return ans;
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
    int answer = getMinDiff(arr, n, k);
    cout << "Min difference in height " << answer;
    return 0;
}