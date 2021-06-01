/*
to check a number is power of 2 or not


2 power has only 1 set bit like for number 8 it is 1000 
n-1 = 8-1 = 7 is 0111
8&7 = 0000  (everytime) all 0

*/

#include <bits/stdc++.h>
using namespace std;

bool isPowerof2(int n)
{
    return (n && !(n & (n - 1))); //if zero then return true (n&& if n = 0 then full expression 0 (n&&))
}
int main()
{
    cout << isPowerof2(8) << endl;
    cout << isPowerof2(0) << endl; //corner case
    cout << isPowerof2(3) << endl;
    return 0;
}