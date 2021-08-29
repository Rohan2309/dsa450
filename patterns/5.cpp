/*
1    
2 2      
3 3 3        
4 4 4 4          
5 5 5 5 5      

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
        for (j = 1; j <= i; ++j) //for cols

        {

            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}