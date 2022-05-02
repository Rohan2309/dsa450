/*
131. Palindrome Partitioning
Medium

6025

181

Add to List

Share
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s , int st, int en){
        while(st<=en){
            if(s[st++]!=s[en--])return false;
        }
        return true;
    }
    void helper(int idx,string s, vector<string>&v,int n, vector<vector<string>>&ans){
        if(idx==n){//base case when index reaches end
            ans.emplace_back(v);
            return;
        }
        for(int i=idx; i<n; ++i){//0 to last we can put a partition
            if(isPalindrome(s,idx,i)){//we can only put a partition when str is palindrome
                v.emplace_back(s.substr(idx,i-idx+1));//storing the substring if it's a palindrome
                helper(i+1,s,v,n,ans);//from next index
                v.pop_back();//after all func calls have been made, remove eles from ds
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;//individual list of sub strings
        int n=s.size();
        helper(0,s,v,n,ans);//start index = 0
        return ans;
    }
};
int main()
{
    
    return 0;
}