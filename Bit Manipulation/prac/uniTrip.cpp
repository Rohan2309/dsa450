/*
To find a unique number in an array where all numbers except one , are present thrice.

1  001
3  110
2  010
3  110
4  100
2  010
1  001
1  001
3  110
2  010


array -> (int size 64) -> 64 bits array

0 1 2
3 6 4

modulo by 3 gives
0 0 1

it gives

4 in binary form is 100

position of accourding to binary representation fill the array
 for 0 position of array we have to check which element have setbit in 0 pos
 only 1 has set bit in 0 position and it occurs 3 times

 same for position 1 -> 6  for 2 -> 4

 all which have triplets will be multiple of 3



*/

#include <bits/stdc++.h>
using namespace std;

bool getBit(int n, int pos)
{
    return (n & (1 << pos)) != 0; //if not = zero we have 1 in that pos
}

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

int uniTrip(int a[], int n)
{
    int result = 0;

    for (int i = 0; i < 64; i++) //array of 64 bits (to cover all bits)
    {
        int sum = 0;
        for (int j = 0; j < n; j++) //traverse the array
        {
            if (getBit(a[j], i)) //arr[j]'s ith bit is set or not
            {
                sum++;
            }
        }
        if (sum % 3 != 0) //element which is not in triplet
        {
            result = setBit(result, i);
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 3, 2, 3, 4, 2, 1, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << uniTrip(arr, n) << endl;
    return 0;
}