/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in 
the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &v)
{
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        minPrice = min(minPrice, v[i]);
        maxProfit = max(maxProfit, v[i] - minPrice);
    }
    return maxProfit;
}

int main()
{
    vector<int> vect{7, 1, 5, 3, 6, 4};
    int ans = maxProfit(vect);
    cout << ans << endl;
    return 0;
}