/*
Kth element in Matrix 
Given a N x N matrix, where every row and column is sorted in non-decreasing order.
 Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
 

Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.
*/

#include <bits/stdc++.h>
using namespace std;

int count(int a[10][10], int n, int m, int mid)
{
    int count = 0; //to store count of values smaller or equal to mid
    int j = m - 1; //from reverse
    for (int i = 0; i < n; i++)
    {
        for (j; j >= 0; j--)
        {
            if (a[i][j] <= mid)
            {
                count += j + 1;
                //no of columns +1 (col no. starts from 0)
                break;
            }
        }
    }
    return count;
}

int kSmall(int a[10][10], int n, int m, int k)
{

    int low = a[0][0];
    int high = a[n - 1][m - 1];
    while (low < high)
    {
        int mid = floor((high - low) / 2 + 1);
        int c = count(a, n, m, mid);
        if (c >= k)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    int a[10][10], i, j, n, m, k;

    cout << "Enter number of rows  (between 1 and 10): ";
    cin >> n;
    cout << "Enter number of columns  (between 1 and 10): ";
    cin >> m;

    cout << endl
         << "Enter elements of the matrix: " << endl;

    // Storing elements of first matrix entered by user.
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }
    }

    cout << "Enter value of k (kth smallest element): ";
    cin >> k;

    int ans = kSmall(a, n, m, k);
    cout << ans << endl;
    return 0;
}