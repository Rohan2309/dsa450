/*
* * * *
* * * *
* * * *
* * * *
* * * *

Rows 5
Cols 4

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int rows = 5, cols = 4;
    int i, j;
    for (i = 0; i < rows; ++i)
    {
        for (j = 0; j < cols; ++j)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}