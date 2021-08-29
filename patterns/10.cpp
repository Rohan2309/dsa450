/*
          * * * *
        * * * *
      * * * *
    * * * *
  * * * *

n 5
rows 1 to n
cols 
n-i = spaces at first {space print from 1 to n-i}
then print starts 1 to n

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n - i; ++j)
        {
            cout << "  ";
        }
        for (j = 0; j < n; ++j)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}