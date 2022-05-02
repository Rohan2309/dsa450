#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> pref;
    NumArray(vector<int>& nums) {
        int n = nums.size();
		pref.clear();
        for(int i = 0; i < n; i++){
            if(i == 0)pref.push_back(nums[i]);
            else pref.push_back(nums[i] + pref[i - 1]);
        }
    }  
    int sumRange(int left, int right) {
        if(left == 0)return pref[right];//because it's the cum sum till that point
        //no ele in left
        return pref[right] - pref[left - 1]; 
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
