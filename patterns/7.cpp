/*
n=4
*             *   
* *         * *      
* * *     * * *        
* * * * * * * *          
* * * * * * * *     
* * *     * * *       
* *         * *   
*             *

2*n rows and cols
*             *   for spaces row = 1   spaces = 6 so (2*n)-(2*i) = 2*4 - 2*1 = 6 spaces
* *         * *      
* * *     * * *        
* * * * * * * *          

rows = n and cols = 2n

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    int i, j;
    //for first half
    for (i = 0; i <= n; ++i) //for rows
    {
        for (j = 0; j < i; ++j) //for cols
        {

            cout << "* "; //printing first star
        }
        int space = (2 * n) - (2 * i);
        for (j = 0; j < space; j++)
        {
            cout << "  "; //printing spaces
        }
        for (j = 0; j < i; ++j)
        {

            cout << "* "; //printing last star
        }
        cout << endl;
    }
    //for 2nd half
    for (i = n; i >= 0; --i) //for rows
    {
        for (j = 0; j < i; ++j) //for cols
        {

            cout << "* "; //printing first star
        }
        int space = (2 * n) - (2 * i);
        for (j = 0; j < space; j++)
        {
            cout << "  "; //printing spaces
        }
        for (j = 0; j < i; ++j)
        {

            cout << "* "; //printing last star
        }
        cout << endl;
    }
    return 0;
}