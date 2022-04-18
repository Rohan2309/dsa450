/*
Minimize Bill
Difficulty: EASY
Contributed By
Himanshu Airan
|
Level 4
Avg. time to solve
10 min
Success Rate
80%
Problem Statement
You are buying some items from a grocery store and now it’s time to pay the bill. The bill is represented in the form of an integer array 'A' consisting of 'N' integers. The integers in array 'A' denotes the cost of items you purchased.
You get a chance to make a change in the bill. In one change, you can select any index 'i' in array 'A' and multiply element 'A[i]' by -1.
Your task is to perform exactly one change in the bill such that the sum of elements in array 'A', i.e., total amount you need to pay is the minimum possible. Return the minimum possible sum after making a change.
Note :
Cost of items (elements in 'A') and total amount of bill is allowed to be negative.
Example :
N = 4
A = [2, 3, 5, 1]

You are supposed to perform exactly one change. The optimal way is performing change on A[2] = 5. Minimum sum of array (after change) becomes 2+3+(-5)+1 = 1.
Input Format :
The first line contains an integer 'T', denoting the number of test cases.
Then the test cases follow:

The first line of each test case contains an integer 'N', denoting the size of the array 'A'.

The second line contains 'N' space-separated integers, denoting the array 'A' elements.
Output Format :
For each test case, print an integer denoting the minimum sum of array 'A' (amount you need to pay) after exactly one change is done.

Print the output of each test case in a new line.
Note :
You are not required to print the expected output. It has already been taken care of. Just implement the function.
Constraints -
1 <= 'T' <= 10
1 <= 'N' <= 10^5
-10^6 <= 'A[i]' <= 10^6
Sum of 'N' over all test cases doesn’t exceed 10^5.

Time Limit: 1 sec
Sample Input 1 :
2
5
-2 0 5 2 -1
4
5 8 7 9
Sample Output 1 :
-6
11
Explanation For Sample Input 1 :
For test case 1:
The optimal way is to make change at A[2]. Minimum sum of array (after change) becomes -2+0+(-5)+2-1 = -6.

For test case 2:
Make change at A[3]. Minimum sum becomes 5+8+7+(-9) = 11.
Sample Input 2 :
3
4
3 -1 0 2
2
0 -1
5
5 5 5 5 5
Sample Output 2 :
-2
-1
15
*/

#include <bits/stdc++.h>
using namespace std;

long long totalBill(int n, vector<int>& a)
{
    // Write your code here.
    
    int sum =0;
    int idx;
    int maxi = INT_MIN;
    for(int i=0; i<n; ++i){
        if(a[i]>maxi){
            maxi=a[i];
            idx=i;
        }
    }
    a[idx]*=-1;
    for(int i=0; i<n; ++i){
        sum+=a[i];
    }
    return sum;
}
int main() {
	return 0;
}