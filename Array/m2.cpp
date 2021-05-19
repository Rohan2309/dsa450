/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.
space 0(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int s, e;
};

bool comp(Interval a, Interval b)
{
    if (a.s < b.s)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void merge(Interval arr[], int n)
{
    sort(arr, arr + n, comp); //custom sort
    int index = 0;            //index of last element in o/p array
    for (int i = 1; i < n; i++)
    {
        if (arr[index].e >= arr[i].s)
        {
            arr[index].e = max(arr[index].e, arr[i].e);
            arr[index].s = min(arr[index].s, arr[i].s);
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }
    cout << "the merged intervals are : ";
    for (int i = 0; i <= index; i++)
    {
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
    }
}

int main()
{
    Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}}; //array of struct type
    int n = sizeof(arr) / sizeof(arr[0]);
    merge(arr, n);
    return 0;
}