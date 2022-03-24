/*
14. Longest Common Prefix
Easy

7360

2883

Add to List

Share
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mi = INT_MAX;
        if(strs.size()==0){
            return "";
        }
        if(strs.size()==1)
        {
            return strs[0];
        }
        string ans = strs[0];//taking first str as array as current ans
        int n = strs.size();
        
        for(int i=1; i<n; i++){//from 2nd element
            int j=0;//iterator for first element i.e flower
            int k=0;//iterator for rest elements 
            int a=0;//will have ans
            while(j<ans.size() and k<strs[i].size()){
                if(ans[j]==strs[i][k]){//i is row number and k is column number for remaining strings
                    a++;
                }
                else{
                    break;
                }
                j++;//incre pointer
                k++;
            }
            mi = min(mi,a);
            
        }
        return ans.substr(0,mi);
    }
};

int main()
{

    return 0;
}