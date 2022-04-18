/*
2170. Minimum Operations to Make the Array Alternating
User Accepted:2819
User Tried:7511
Total Accepted:2884
Total Submissions:19403
Difficulty:Medium
You are given a 0-indexed array nums consisting of n positive integers.

The array nums is called alternating if:

nums[i - 2] == nums[i], where 2 <= i <= n - 1.
nums[i - 1] != nums[i], where 1 <= i <= n - 1.
In one operation, you can choose an index i and change nums[i] into any positive integer.

Return the minimum number of operations required to make the array alternating.

 

Example 1:

Input: nums = [3,1,3,2,4,3]
Output: 3
Explanation:
One way to make the array alternating is by converting it to [3,1,3,1,3,1].
The number of operations required in this case is 3.
It can be proven that it is not possible to make the array alternating in less than 3 operations. 
Example 2:

Input: nums = [1,2,2,2,2]
Output: 2
Explanation:
One way to make the array alternating is by converting it to [1,2,1,2,1].
The number of operations required in this case is 2.
Note that the array cannot be converted to [2,2,2,2,2] because in this case nums[0] == nums[1] which violates the conditions of an alternating array.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int freqEven[100001]={0};//frq array, 1->10^5 constraint (of even elements)
        int freqOdd[100001]={0};//frq array, 1->10^5 constraint (of odd elements)
        int n = nums.size();
        int ans = 0;
        int maxi=nums[0];
        //frquency array filling
        for(int i=0;i<n;++i){
            if(i%2==0){
                freqEven[nums[i]]++;
            }
            else{
                freqOdd[nums[i]]++;
            }
            maxi=max(nums[i],maxi);
        }
        int firstMaxEven=0;
        int freqFirstMaxEven=0;
        int firstMaxOdd=0;
        int freqFirstMaxOdd=0;
        int secondMaxEven=0;
        int freqSecondMaxEven=0;
        int secondMaxOdd=0;
        int freqSecondMaxOdd=0;
        
        for(int i=1;i<=maxi;++i){//going across all the numbers
            if(freqEven[i]>freqFirstMaxEven){
                secondMaxEven=firstMaxEven;
                freqSecondMaxEven=freqFirstMaxEven;
                freqFirstMaxEven=freqEven[i];
                firstMaxEven=i;
            }
            else if(freqEven[i]>freqSecondMaxEven){
                freqSecondMaxEven=freqEven[i];
                secondMaxEven=i;
            }
            if(freqOdd[i]>freqFirstMaxOdd){
                secondMaxOdd=firstMaxOdd;
                freqSecondMaxOdd=freqFirstMaxOdd;
                freqFirstMaxOdd=freqOdd[i];
                firstMaxOdd=i;
            }
            else if(freqOdd[i]>freqSecondMaxOdd){
                freqSecondMaxOdd=freqOdd[i];
                secondMaxOdd=i;
            }
        }
        if(firstMaxEven != firstMaxOdd){//when p!=q
            return n - freqFirstMaxEven - freqFirstMaxOdd;
        }
        else{//when p=q
            return min(n-freqFirstMaxEven-freqSecondMaxOdd, n-freqFirstMaxOdd-freqSecondMaxEven);
        }
    }
};
int main() {
	return 0;
}