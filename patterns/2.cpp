/*
* * * *
*     *
*     *
*     *
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
            if (i == 0 or i == rows - 1) //when 1st row or last row
            {
                cout << "* ";
            }
            else if (j == 0 or j == cols - 1) //when 1st column or last column
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}