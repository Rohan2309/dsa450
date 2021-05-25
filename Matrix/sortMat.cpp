/*
Given an NxN matrix Mat. Sort all elements of the matrix.

Example 1:

Input:
N=4
Mat=[[10,20,30,40],
[15,25,35,45] 
[27,29,37,48] 
[32,33,39,50]]
Output:
10 15 20 25 
27 29 30 32
33 35 37 39
40 45 48 50
Explanation:
Sorting the matrix gives this result.
*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

void sortMat(int A[SIZE][SIZE], int n)
{
    int temp[SIZE * SIZE], k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[k++] = A[i][j];
        }
    }
    sort(temp, temp + k);
    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = temp[k++];
        }
    }
}

void printMat(int A[SIZE][SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int a[SIZE][SIZE], i, j, n;

    cout << "Enter number of rows and columns (between 1 and 10): ";
    cin >> n;

    cout << endl
         << "Enter elements of the matrix: " << endl;

    // Storing elements of first matrix entered by user.
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }
    }
    sortMat(a, n);
    printMat(a, n);

    return 0;
}