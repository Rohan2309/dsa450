/*
to generate all possible subsets of a set
{a,b,c}  n size set -> subsets willbe 2^n    (0 to 2^n-1)

{}        000    0  (0)
{c}       001    1
{b}       010    2
{b,c}     011    3
{a}       100    4
{a,c}     101    5
{a,b}     110    6
{a,b,c}   111    7  (2^n - 1)

loop from 0 to 2^n-1
check setbit(1) -> print corresponding object in set
*/

#include <bits/stdc++.h>
using namespace std;

void subsets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++) // 1<<n -> 2^n
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j)) //getBit (if j bit is set in out number)
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int arr[4] = {1, 2, 3, 4};
    subsets(arr, 4);
    return 0;
}