/*
   
    *        *
  *   *    *   *    
*       *        *    

n=9
rows = 3 
cols
chech col and row no of stars
when we add i+j we get 4,6,8,10,12
so i+j%4==0 will be acceptable for 4 and 8 and 12
but for 6 and 10
when i = 2 and j%4==0
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 9;
    int i, j;
    for (i = 1; i <= 3; ++i) //for rows
    {
        for (j = 1; j <= n; ++j) //for cols

        {
            if ((j + i) % 4 == 0 or (i == 2 and j % 4 == 0))
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