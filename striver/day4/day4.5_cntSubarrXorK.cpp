/*

Subarray with given XOR
Medium

164

4

Add to favorites
Asked In:
DUNZO
Problem Description

Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.



Problem Constraints
1 <= length of the array <= 105

1 <= A[i], B <= 109



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the total number of subarrays having bitwise XOR equals to B.



Example Input
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 5


Example Output
Output 1:

 4
Output 2:

 2


Example Explanation
Explanation 1:

 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Explanation 2:

 The subarrays having XOR of their elements as 2 are [5] and [5, 6, 7, 8, 9]

*/


#include<bits/stdc++.h>
using namespace std;


class Solution{ 
    public:
    int solve(vector<int> &A, int B) {

        long long cnt = 0;
    int xr = 0;
    unordered_map<int,int>hashMap;//y along with count
    int n = A.size();
    for(int i=0; i<n; ++i){
        xr^=A[i]; //will have prefix xor
        if(xr==B){
            cnt++;
        }
        int y = xr^B;
        if(hashMap.find(y)!=hashMap.end()){//if y already in map
            cnt+=hashMap[y];//incre with no. of times y present
        }
        //lastly updating the value in hashMap
        hashMap[xr]++;
    }
    return cnt;
    
    }
};

int main()
{   vector<int> A{ 4,2,2,6,4 };
    Solution obj;
    int totalCount= obj.solve(A,6);
    cout<<"The total number of subarrays having a given XOR k is "<<totalCount<<endl;
}