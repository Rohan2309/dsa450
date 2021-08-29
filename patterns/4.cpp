/*
        *    i=1 (row) spaces = 0 so n-i spaces  {n=5} and add * till n
      * *      
    * * *        
  * * * *          
* * * * *    i=5    

Rows 5


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int i, j;
    for (i = 1; i <= n; ++i) //for rows
    {
        for (j = 1; j <= n; ++j) //for cols

        {
            if (j <= n - i)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }

    return 0;
}