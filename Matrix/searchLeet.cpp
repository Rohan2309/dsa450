/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the 
following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

*LEET CODE VERSION*
*/

#include <bits/stdc++.h>
using namespace std;

int searchmatrix(int a[10][10], int r, int c, int x)
{

    int flag = 0;
    int low = 0, high = (r * c) - 1;
    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (a[mid / c][mid % c] == x)
        {
            flag = 1;
        }
        if (a[mid / c][mid % c] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return flag;
}
int main()
{
    int r, c, a[10][10], i, j, x;

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
    cout << "Exnter value of x: " << endl;
    cin >> x;
    int ans = searchmatrix(a, r, c, x);
    if (ans == 1)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}