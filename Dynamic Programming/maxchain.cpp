/*
Max length chain 
You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs. 
 

Example 1:

Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3
Explanation: The given pairs are { {5, 24}, {39, 60},
{15, 28}, {27, 40}, {50, 90} },the longest chain that
can be formed is of length 3, and the chain is
{{5, 24}, {27, 40}, {50, 90}}

*GREEDY APPROACH
*/

#include <bits/stdc++.h>
using namespace std;

struct val
{
    int first;
    int second;
};

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maxChainLen(struct val p[], int n)
{
    //Your code here
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) //storing elements in vector
    {
        v.push_back({p[i].first, p[i].second});
    }
    //sorting with second value
    sort(v.begin(), v.end(), comp);
    int i = 0; //pointing first value
    int j = 1; //pointing second value
    int c = 1; //counter is 1 at initial point
    int sz = v.size();

    while (j < sz) //base case
    {
        if (v[i].second < v[j].first) //second value of first pair is smaller than first value of send pair
        {
            c++;
            i = j;
            j++;
        }
        else //if not less then j is shifted forward and i remains same to compare with next value
        {
            j++;
        }
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    val p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    cout << maxChainLen(p, n) << endl;

    return 0;
}