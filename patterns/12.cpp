/*
         1    
       2 1 2      
     3 2 1 2 3        
   4 3 2 1 2 3 4         
 5 4 3 2 1 2 3 4 5 

n=5
Rows  1 to n (i ptr)
cols has 3 parts
space   -> 1 to n-i, when n =5 and row npo is 1 we have 4 spaces
nos in decreasing order n-i to 1 -> k= row number (i), print k-- till 1
nos in incre order -> let k = 2 , k++ till n


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int i, j;
    for (i = 1; i <= n; i++) //for rows
    {
        for (j = 1; j <= n - i; j++) //space   -> 1 to n-i, when n =5 and row npo is 1 we have 4 spaces

        {
            cout << "  ";
        }
        int k = i;          //nos in decreasing order n-i to n -> k= row number (i), print k-- till 1
        for (; j <= n; j++) // j=n-i that is 4 to 5(n) (k is 1)
        {
            cout << k-- << " ";
        }
        k = 2;                      //nos in incre order -> let k = 2 , k++ till
        for (; j <= n + i - 1; j++) //writing in terms of rows
        {
            cout << k++ << " ";
        }
        cout << endl;
    }

    return 0;
}