/*
* * * * *  n=5
* * * *      4
* * *        .
* *          .
*            1

Rows 5


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int i, j;
    for (i = n; i > 0; --i) //for rows
    {
        for (j = 0; j < i; ++j) //for cols
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}