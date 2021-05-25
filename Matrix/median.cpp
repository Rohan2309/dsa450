/*
Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.
Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5
*/

#include <bits/stdc++.h>
using namespace std;

int med(int a[10][10], int r, int c)
{
    int minElement = INT_MIN, maxElement = INT_MAX;
    for (int i = 0; i < r; i++)
    {
        minElement = min(minElement, a[i][0]);
        maxElement = max(maxElement, a[i][c - 1]);
    }
    int desired = (r * c + 1) / 2; //index of median if matrix is put in array format
    while (minElement < maxElement)
    {
        int mid = minElement + (maxElement - minElement) / 2;
        int totalCount = 0; //no of elements <= mid
        for (int i = 0; i < r; i++)
        {
            totalCount += upper_bound(a[i], a[i] + c, mid) - a[i]; //upperbound returns first greater element than mid
        }
        if (totalCount < desired)
        {
            minElement = mid + 1;
        }
        else
        {
            maxElement = mid;
        }
    }
    return minElement;
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
    int ans = med(a, r, c);
    cout << ans << endl;
    return 0;
}