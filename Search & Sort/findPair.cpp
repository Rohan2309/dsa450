/*
Find Pair Given Difference

Given an array Arr[] of size L and a number N, you need to write a program to find if there exists
 a pair of elements in the array whose difference is N.

 Example 1:

Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.
Example 2:

Input:
L = 5, N = 45
arr[] = {90, 70, 20, 80, 50}
Output: -1
Explanation: There is no pair with difference of 45.
Your Task:
You need not take input or print anything. Your task is to complete the function findPair() which takes array arr, size of the array L and N as input parameters and returns True if required pair exists, else return False.

Expected Time Complexity: O(L* Log(L)).
Expected Auxiliary Space: O(1).

0(N) space use map
store array in map
arr[i] +x is present in map or not

method 2 tome(nlogn)
sort arr 2,3,5,5,20,80

2+x = 2+78 = 80
search 80 with binary search

*/

#include <bits/stdc++.h>
using namespace std;

bool solve(int a[], int size, int n)
{
    sort(a, a + size); //sorting array
    int f = -1;        //flag
    for (int i = 0; i < size; i++)
    {                                                                 //upper bound is binary search only (1st contraint stary, second constraint end and third is val to find)
        int idx = upper_bound(a + i + 1, a + size, n + a[i]) - a - 1; //upper bound is binary search which gives last idx of value
        //-a for geeting idx //-1 as we using upper bound we get the later index
        if (a[idx] - a[i] == n) //final check
        {
            f = 1;
            break;
        }
    }
    if (f == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int a[] = {90, 70, 20, 80, 50}, size = sizeof(a) / sizeof(a[0]), n = 5, ans = solve(a, size, n);
    cout << ans << endl;
    return 0;
}