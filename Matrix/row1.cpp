/*
Given a boolean 2D array of n x m dimensions where each row is sorted. 
Find the 0-based index of the first row that has the maximum number of 1's.

Example :

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).
*/

#include <bits/stdc++.h>
using namespace std;
int row1(int a[10][10], int r, int c)
{
    int j = c - 1;
    while (j >= 0 and a[0][j] == 1)
    {
        j--;
    }
    int row = 0;
    for (int i = 1; i < r; i++)
    {
        while (j >= 0 and a[i][j] == 1)
        {
            j--;
            row = i;
        }
    }

    return row;
}
int main()
{

    int r, c, a[10][10], i, j;

    cout << "Enter number of rows (between 1 and 10): ";
    cin >> r;

    cout << "Enter number of columns (between 1 and 10): ";
    cin >> c;
    cout << endl
         << "Enter elements of the matrix: " << endl;

    // Storing elements of first matrix entered by user.
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }
    }
    int ans = row1(a, r, c);
    cout << ans << endl;
    return 0;
}