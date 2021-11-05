/*
75. Sort Colors
Medium

7552

354

Add to List

Share
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int cntRed=0;
        int cntWhite=0;
        int cntBlue=0;
        int i;
        for(i=0; i<n; i++){
            switch(v[i]){
                case 0:
                    cntRed++;
                    break;
                case 1:
                    cntWhite++;
                    break;
                case 2:
                    cntBlue++;
                    break;
            }
        }
        //got total number of red, white blue balls;
        i=0;
        while(cntRed--){
            v[i++]=0;
        }
        while(cntWhite--){
            v[i++]=1;
        }
        while(cntBlue--){
            v[i++]=2;
        }
    }
};

int main(){
    return 0;
}