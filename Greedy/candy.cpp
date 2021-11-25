/*
Shop in Candy Store 
Easy Accuracy: 59.56% Submissions: 9005 Points: 2
In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
You can buy a single candy from the store and get at most K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.

Example 1:

Input:
N = 4
K = 2
candies[] = {3 2 1 4}

Output:
3 7

Explanation:
As according to the offer if you buy 
one candy you can take at most two 
more for free. So in the first case, 
you buy the candy which costs 1 and 
takes candies worth 3 and 4 for free, 
also you buy candy worth 2 as well.
So min cost : 1+2 =3.
In the second case, you can buy the 
candy which costs 4 and takes candies 
worth 1 and 2 for free, also you need 
to buy candy worth 3 as well. 
So max cost : 3+4 =7.
Example 2:

Input: 
N = 5
K = 4
candies[] = {3 2 1 4 5}

Output: 
1 5

Explanation:
For minimimum cost buy the candy with
the cost 1 and get all the other candies
for free.
For maximum cost buy the candy with
the cost 5 and get all other candies
for free.
*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        //n total no of candies available
        //candies[] is price array
        // Write Your Code here
        //k is offer if we buy any candy we can get 2 candies free if available
        vector<int> ans; //answer vector

        int ma = 0; //max amt in which we can buy all candies
        int mi = 0; //min....

        //for min part
        sort(candies, candies + n); //sorting in ascending order

        int i = 0;     //pointer (purchase from first) as cheap candies are at first
        int j = n - 1; //we take free candies from last as they are costly

        while (i <= j)
        {
            mi += candies[i]; //adding up to the price
            i++;              //incre pointer
            j = j - k;        //we can buy atmost k candies for free
        }
        ans.push_back(mi);
        //for max part

        reverse(candies, candies + n); //sort in descending order
        i = 0;                         //pointer purchase from first as costly canties are at first
        j = n - 1;                     //cheap candies for free as they are at the last

        while (i <= j)
        {
            ma += candies[i];
            i++;
            j = j - k;
        }
        ans.push_back(ma);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
} // } Driver Code Ends