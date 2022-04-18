/*

2177. Find Three Consecutive Integers That Sum to a Given Number
User Accepted:9203
User Tried:9765
Total Accepted:9483
Total Submissions:17675
Difficulty:Medium
Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers, return an empty array.

 

Example 1:

Input: num = 33
Output: [10,11,12]
Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].
Example 2:

Input: num = 4
Output: []
Explanation: There is no way to express 4 as the sum of 3 consecutive integers.
 

Constraints:

0 <= num <= 1015

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long n) {
        vector<long long>ans;
        
        if(n%3==0){
            ans.emplace_back(n/3-1);
            ans.emplace_back(n/3);
            ans.emplace_back(n/3+1);
            
        }
        
        return ans;
    }
};
int main() {
	return 0;
}