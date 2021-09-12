/*
49. Group Anagrams
Medium

6776

255

Add to List

Share
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &a)
{
    int n = a.size();

    map<string, vector<string>> m;
    for (int i = 0; i < n; i++)
    {
        string s = a[i];          //picking 1 string in s
        sort(s.begin(), s.end()); //sort
        m[s].push_back(a[i]);     //dgo-> god, dog
    }
    int idx = 0;
    vector<vector<string>> ans(m.size());
    for (auto x : m)
    {
        auto v = x.second; //vect in v
        for (int i = 0; i < v.size(); i++)
        {
            ans[idx].push_back(v[i]);
        }
        idx++;
    }
    return ans;
}

int main()
{

    return 0;
}