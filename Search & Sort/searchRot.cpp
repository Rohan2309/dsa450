/*
Search element in sorted and rotated array
complexity should be less than O(N)
original array 0 1 2 3 4 5 6 7
array rotated from pivot point 7

4 5 6 7 0 1 2 3
low = 4 high = 3
1st search space= 4 5 6 7 
2nd = 0 1 2 3

1st cond
key = 6 
mid = 7
first decide mid is in 1st search space or  2nd
if mid is > low then it is in 1st ss
then check if k is present in 1st or 2nd (greater than low and smaller than mid)
then high = mid -1

2nd cond
mid = 0
key = 2
mid >  low? No
then 2nd ss
then check if k is present in 1st or 2nd (greater than mid and smaller than high)
then low = mid+1


find pivot point -> only element which is greater than next element
binary search in left half then binary search in right half
*/

#include <bits/stdc++.h>
using namespace std;

int searchRot(int a[], int k, int l, int h)
{
    while (l <= h)
    {
        int m = l + h / 2;
        if (a[m] == k)
        {
            return m;
        }
        else if (a[m] > a[l])            //lying in first search space(mid)
        {                                //check mid in lying in which ss
            if (a[m] >= k and a[l] <= k) //lying in first search space(key)
            {                            //check k is lying in which ss
                h = m - 1;
            }
            else //lying in 2nd ss(key)
            {
                l = m + 1;
            }
        }
        else //lying in the 2nd ss (mid)
        {
            if (a[m] <= k and a[h] >= k)
            {
                l = m + 1; //lying in 2nd ss (key)
            }
            else
            {
                h = m - 1; //lying in 1nd ss (key)
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int arr1[] = {30, 40, 50, 10, 20}; //rotated array
    int n = 5;
    int k = 10; //key
    int idx = searchRot(arr1, k, 0, n - 1);
    if (idx == -1)
    {
        cout << "Key doesn't exist";
    }
    else
    {
        cout << "Key exist at key " << idx << endl;
    }
    return 0;
}