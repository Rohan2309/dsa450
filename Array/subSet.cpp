/*
Array Subset of another array 

Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. 
Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. 
It may be assumed that elements in both array are distinct.

*o(n^2) brute*
first check smaller array is present in bigger array

*optimal approach*
hashing
*/

#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> m1;
    for (int i = 0; i < n; i++) //for first array pushing every element in hash map
    {
        m1[a1[i]]++; //hash the value of arr1
    }
    int count = 0;
    for (int i = 0; i < m; i++) //second array
    {
        if (m1[a2[i]]) //if value already present in hashmap
        {
            count++;
        }
    }
    if (count != m) //every value of second array is not present in array 1
    {
        return "No";
    }
    else
    {
        return "Yes";
    }
}

int main()
{
    int a1[] = {11, 1, 13, 21, 3, 7},
        a2[] = {11, 3, 7, 1};
    int n = sizeof(a1) / sizeof(a1[0]);
    int m = sizeof(a2) / sizeof(a2[0]);
    cout << isSubset(a1, a2, n, m) << endl;
    return 0;
}