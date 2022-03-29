/*
242. Valid Anagram
Easy

4451

203

Add to List

Share
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

//approach 1 to sort the array
//approach 2 to use array as hashmap of sz 26 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        if(s==t)return true;
        int n = s.size();
        unordered_map<char,int>mp;
        for(int i=0; i<n;++i ){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto i: mp){
            if(i.second)return false;
        }
        return true;
    }
}; 

int main()
{

    return 0;
}