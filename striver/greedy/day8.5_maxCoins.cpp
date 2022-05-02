/*
Find Minimum Number Of Coins
Difficulty: EASY
Contributed By
Sakshi Bansal
|
Level 1
Avg. time to solve
15 min
Success Rate
85%
Problem Statement
Dora, the explorer, visits India and decides to try the famous Indian food. However, the restaurant accepts only Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins.
So, Dora goes to a bank that has an infinite supply of each of the denominations to make a change for a given ‘Amount’ of money. As a cashier at the bank, your task is to provide Dora the minimum number of coins that add up to the given ‘Amount’.
For Example
For Amount = 70, the minimum number of coins required is 2 i.e an Rs. 50 coin and a Rs. 20 coin.
Note
It is always possible to find the minimum number of coins for the given amount. So, the answer will always exist.
Input Format
The first line of input contains an integer 'T' representing the number of test cases or queries to be processed. Then the test case follows.

The only line of each test case contains a single integer ‘Amount’ representing the amount Dora wishes to change to Indian currency.
Output Format
For each test case, print the minimum number of coins needed to make the change.

Print the output of each test case in a separate line.
Note
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints
1 <= T <= 100
1 <= Amount <= 10^5
Where 'T' is the number of test-cases
Time Limit: 1sec
Sample Input 1
2
13
20
Sample Output 1
3
1
Explanation Of Sample Input 1
For the First Test Case ,the minimum number of coins to make the change are 3 {1, 2, 10}.

For the second Test Case, only one coin {20} is required.
Sample Input 2
2
50
96
Sample Output 2
1
5
 
*/

#include <bits/stdc++.h>
using namespace std;

int findMinimumCoins(int amount) 
{
    // Write your code here
    int arr[]={1,2,5,10,20,50,100,500,1000};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cnt = 0;//final ans
    for(int i = n-1; i>=0; --i){//backward
        while(amount>=arr[i]){
            amount-=arr[i];
            cnt++;
        }
    }
    return cnt;
}




int main()
{
    
    return 0;
}