/*
Majority Element

Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
Example 2:

Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element.

Your Task:
The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.
 
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int n)
{
    int val = n / 2;
    int count = 1;    //atleast 1
    int first = a[0]; //store first element

    for (int i = 1; i < n; i++) //loop from second element
    {

        if (a[i] == first)
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0) //resetting value
        {
            first = a[i];
            count = 1;
        }
    }

    //after this step predicted majority element is in first
    int c = 0; //counter of first
    for (int i = 0; i < n; i++)
    {
        if (a[i] == first)
        {
            c++;
        }
    }
    if (c > n / 2)
    {
        return first;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int arr[] = {3, 1, 3, 3, 2}, n = 5;
    int ans = majorityElement(arr, n);
    cout << ans << endl;
    return 0;
}