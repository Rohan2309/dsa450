/*
Given a matrix of size r*c. Traverse the matrix in spiral form.
*/

#include <bits/stdc++.h>
using namespace std;
void print(vector<int> const &a);
int spiralOrder(int A[10][10], int r, int c)
{

    int Top, Bottom, Left, Right, dir;
    Top = 0;
    Bottom = r - 1;
    Left = 0;
    Right = c - 1;
    dir = 0;
    int i;
    vector<int> ans;

    while (Top <= Bottom && Left <= Right)
    {
        if (dir == 0)
        {
            for (i = Left; i <= Right; i++)
                ans.push_back(A[Top][i]);
            Top++;
        }
        else if (dir == 1)
        {
            for (i = Top; i <= Bottom; i++)
                ans.push_back(A[i][Right]);
            Right--;
        }
        else if (dir == 2)
        {
            for (i = Right; i >= Left; i--)
                ans.push_back(A[Bottom][i]);
            Bottom--;
        }
        else if (dir == 3)
        {
            for (i = Bottom; i >= Top; i--)
                ans.push_back(A[i][Left]);
            Left++;
        }
        dir = (dir + 1) % 4;
    }
    print(ans);
    return 0;
}
void print(vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << ' ';
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
    spiralOrder(a, r, c);
    return 0;
}