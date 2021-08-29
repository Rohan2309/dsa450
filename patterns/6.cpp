/*
1    
2 3      
4 5 6        
7 8 9 10          
1112131415      

Rows 5


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int cnt = 1;
    int i, j;
    for (i = 1; i <= n; ++i) //for rows
    {
        for (j = 1; j <= i; ++j) //for cols

        {

            cout << cnt << " ";
            ++cnt;
        }
        cout << endl;
    }

    return 0;
}