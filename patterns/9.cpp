/*
1    
0 1      
1 0 1        
0 1 0 1          
1 0 1 0 1      

Rows 5=n   1 to n
cols       1 to i(row no)


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int i, j;
    for (i = 1; i <= n; ++i) //for rows
    {
        for (j = 1; j <= i; ++j) //for cols

        {
            if ((j + i) % 2 == 0) //when we are adding row and col no we are getting an even number
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}