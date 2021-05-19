/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    { //pushing elements
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());          //sorting (wrt first parameter)
    stack<pair<int, int>> s;           //taking a stack (pair wise)
    s.push({a[0].first, a[0].second}); //inserting first element into stack
    for (int i = 1; i < n; i++)
    {
        int start1 = s.top().first;
        int end1 = s.top().second;
        int start2 = a[i].first;
        int end2 = a[i].second;

        if (end1 < start2)
        {
            s.push({start2, end2}); //pushing new element in stack
        }
        else
        {
            s.pop();
            end1 = max(end1, end2); //updating elements
            s.push({start1, end1});
        }
    }
    while (!s.empty()) //printing stack
    {
        cout << s.top().first << " " << s.top().second << endl;
    }
    return 0;
}