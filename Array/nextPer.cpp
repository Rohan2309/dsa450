/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation 
of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order 
(i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.
*/

#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &a)
{
    int index = -1;
    int n = a.size();
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] > a[i - 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        int previous = index;
        for (int i = index + 1; i < n; i++)
        {
            if (a[i] > a[index - 1] && a[i] <= a[previous])
            {
                previous = i;
            }
        }
        swap(a[index - 1], a[previous]);
        reverse(a.begin() + index, a.end());
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
}
int main()
{
    vector<int> vect;

    vect.push_back(1);
    vect.push_back(5);
    vect.push_back(8);
    vect.push_back(4);
    vect.push_back(7);
    vect.push_back(6);
    vect.push_back(5);
    vect.push_back(3);
    vect.push_back(1);
    nextPermutation(vect);
    return 0;
}