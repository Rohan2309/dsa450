/*
Given an array of integers where each element represents the max number of steps that can be made forward
from that element. Find the minimum number of jumps to reach the end of the array (starting from the first
element). If an element is 0, then you cannot move through that element.
*/

#include <bits/stdc++.h>
using namespace std;

int minJump(int arr[], int n)
{
    int maxReachablePoint = arr[0];
    int step = arr[0];
    int jump = 1; //min jump atleast
    if (n == 1)
    {
        return 0; //base case 1
    }
    else if (arr[0] == 0)
    {
        return -1; //base case 2
    }
    else
    {
        for (int i = 1; i < n; i++) //starting from 1 because 1st value is considered earlier
        {
            if (i == n - 1)
            {
                return jump; //reached last element
            }
            maxReachablePoint = max(maxReachablePoint, arr[i] + i); //+i because to see till where we can reach
            step--;
            if (step == 0)
            {
                jump++;
                if (i >= maxReachablePoint)
                {
                    return -1;
                }
                else
                {
                    step = maxReachablePoint - i; //to update step
                }
            }
        }
    }
}
int main()
{
    int n, arr[11], k;
    cout << "enter total no of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter value of element " << i + 1 << endl;
        cin >> arr[i];
    }
    int ans = minJump(arr, n);
    cout << "Min no of jumps needed " << ans << endl;
    return 0;
}