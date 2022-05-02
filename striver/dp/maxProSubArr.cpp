#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro1 = INT_MIN; // from left to right
        int maxPro2 = INT_MIN; // from right to left
        int n = nums.size();
        
        if(n==1)return nums[0];
        
        int prod = 1;
        //traversing from left to right
        //storing max value in maxPro1
        for(int i=0; i< n; i++){
            
            if(nums[i]==0){
                prod = 1;
            }else{
                prod*=nums[i];
                maxPro1 = max(maxPro1,prod);
            }
            
        }
        
        prod = 1;//resetting product
        
        //traversing from right to left
        //storing max value in maxPro2
        for(int i = n-1; i>0; i--){
            
            
            if(nums[i]==0){
                prod =1;
            }else{
                prod*=nums[i];
                maxPro2 = max(maxPro2,prod);
            }
        }
        int res = max(maxPro1, maxPro2); 
        //incase it is a negative value
        return max(res, 0);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
