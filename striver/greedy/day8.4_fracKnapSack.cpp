/*
Fractional Knapsack 
Medium Accuracy: 45.14% Submissions: 57069 Points: 4
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 
Example 2:

Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.
 
*/

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    static bool comp(Item a, Item b){ //sort desc order value by weight ratio
        //then sum will be maximum
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        return r1>r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        
        sort(arr,arr+n,comp); // sort in desc order
        int curWeight = 0;                                              //adding weight
        double ans = 0;                                         //storing max answer
        for (int i = 0; i < n; i++)
        {
            if (curWeight + arr[i].weight <= W) // checking if lesser than max weight
            {
                ans += arr[i].value;
                curWeight += arr[i].weight;
            }
            else //when greater we will take part of it
            {
                double x = (W - curWeight) * 1.0;//simple mathematics
                ans += (x * ((double)arr[i].value/(double)arr[i].weight)); 
                break;
            }
        }
        return ans;
    }
        
};


int main()
{
    
    return 0;
}