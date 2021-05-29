/*
Common elements in all rows of a given matrix
*/

#include <bits/stdc++.h>
using namespace std;

void commonElements(int a[10][10], int n, int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < m; i++) //initializing first row elements with value 1
    {
        mp[a[0][i]] = 1;
    }
    for (int i = 1; i < n; i++) //checking from second row
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[a[i][j]] == i) //if element is present in map
            {
                mp[a[i][j]] = i + 1;                 //count increasing by 1
                if (i == n - 1 and mp[a[i][j]] == n) //if last row
                {
                    cout << a[i][j] << " ";
                }
            }
        }
    }
}

int main()
{

    int a[10][10], i, j, n, m;

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
    commonElements(a, n, m);

    return 0;
}