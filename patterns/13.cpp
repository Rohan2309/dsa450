/*
         *    
      *  *  *      
   *  *  *  *  *        
*  *  *  *  *  *  *  
*  *  *  *  *  *  *      
   *  *  *  *  * 
      *  *  *    
         *
         
         *    
      *  *  *      
   *  *  *  *  *        
*  *  *  *  *  *  *  

rows 1 to n
cols 
spaces n-i
stars 2*i - 1 will give stars will give me odd nos
        

n=4
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    int i, j;
    int cnt = 0;
    //for first half
    for (i = 1; i <= n; ++i) //for rows
    {

        for (j = 1; j <= n - i; ++j) //for spaces

        {
            cout << "  ";
        }
        for (j = 1; j <= (2 * i) - 1; ++j) //for stars  (2*i - 1 will give stars will give me odd nos)

        {

            cout << "* ";
        }
        cout << endl;
    }
    //for 2nd half
    for (i = n; i >= 1; --i) //for rows
    {

        for (j = 1; j <= n - i; ++j) //for spaces

        {
            cout << "  ";
        }
        for (j = 1; j <= (2 * i) - 1; ++j) //for stars  (2*i - 1 will give stars will give me odd nos)

        {

            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}