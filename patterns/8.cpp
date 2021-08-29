/*
1 2 3 4 5  n=5
1 2 3 4      4
1 2 3        .
1 2          .
1            1

Rows 5


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int i, j;
    int cnt = 1;
    for (i = n; i > 0; --i) //for rows
    {
        for (j = 0; j < i; ++j) //for cols
        {
            cout << cnt++ << " ";
        }
        cnt = 1;
        cout << endl;
    }

    return 0;
}