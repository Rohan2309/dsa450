/*
         1    
       1  2      
     1  2  3        
   1  2  3  4          
 1  2  3  4  5    

n=5
Rows  i to n (i ptr)
space will be n-i
cols 1 to i numbers

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int i, j;
    int cnt = 0;
    for (i = 1; i <= n; ++i) //for rows
    {
        for (j = 1; j <= n; ++j) //for cols

        {

            if (j <= n - i)
            {
                cout << " ";
            }
            else
            {
                cout << ++cnt << " ";
            }
        }
        cnt = 0;
        cout << endl;
    }

    return 0;
}