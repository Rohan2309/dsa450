/*
Longest consecutive subsequence

Given an array of positive integers. Find the length of the longest sub-sequence such that
 elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 
*/

#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int a[], int n)
{
    //Your code here
    set<int> hashSet;           //defing hash set
    for (int i = 0; i < n; i++) //inserting all elements of array in hashset
    {
        hashSet.insert(a[i]);
    }
    int maxl = INT_MIN; //longest streak
    for (int i = 0; i < n; i++)
    {
        if (!hashSet.count(a[i] - 1)) //number lesser than i exists or not in the hash set
        {                             //if not present in hashset (finding smallest in range)
            int cNum = a[i];          //current number
            int curL = 1;             //current streak

            while (hashSet.count(cNum + 1)) //if number hreater than i exists
            {
                cNum += 1; //changing current number
                curL += 1; //increasing current streak
            }
            maxl = max(maxl, curL);
        }
    }
    return maxl;
}
int main()
{
    int a[] = {2, 6, 1, 9, 4, 5, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << findLongestConseqSubseq(a, n) << endl;
    return 0;
}