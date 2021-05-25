/*
Write an efficient algorithm that searches for a target value in an m x n integer matrix. 
The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.


*GFG VERSION*
*/

#include <bits/stdc++.h>
using namespace std;

int searchmatrix(int a[10][10], int r, int c, int x)
{
    int i = 0, j = c - 1, flag = 0;
    while (i < r and j >= 0)
    {
        if (a[i][j] == x)
        {
            flag = 1;
        }
        if (a[i][j] > x)
        {
            j--;
        }
        else
        {
            i++;
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