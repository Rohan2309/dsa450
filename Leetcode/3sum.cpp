/*
15. 3Sum
Medium

12737

1238

Add to List

Share
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans; //will have the result to be returned

    for (int i = 0; i < n - 2; i++)
    { //loop for a, it will go till 3rd lasr element 2nd last b and 3rd last c
        if (i == 0 or (i > 0 and (nums[i] != nums[i - 1])))
        {
            //when a is first element we move into the loop
            //the or part says  that the next a should not be same as prev a
            int low = i + 1;       //it is b
            int high = n - 1;      //it is c
            int sum = 0 - nums[i]; //-a
            while (low < high)
            {
                //valid case
                if ((nums[low] + nums[high]) == sum)
                { //b+c=-a
                    vector<int> arr;
                    arr.push_back(nums[i]);
                    arr.push_back(nums[low]);
                    arr.push_back(nums[high]);
                    ans.push_back(arr);
                    while (low < high and (nums[low] == nums[low + 1]))
                    {          //while b is same skipping
                        low++; //coming till last same b
                    }
                    low++; //taking different b(next)
                    while (low < high and (nums[high] == nums[high - 1]))
                    {           //while c is same skipping
                        high--; //coming to last same c
                    }
                    high--; //taking diff c(next)
                }
                //invalid cases
                else if ((nums[low] + nums[high]) < sum)
                {
                    low++; //will increase value
                }
                else
                {
                    high--; //will decrease value
                }
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}