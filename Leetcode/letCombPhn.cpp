/*
17. Letter Combinations of a Phone Number
Medium

7265

570

Add to List

Share
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> m;

vector<string> letterCombinations(string digits)
{
    int n = digits.size();
    vector<string> res;
    if (n == 0)
    {
        return res;
    }
    string s;
    m = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; //vector of strings..hashmap
    dfs(s, digits, 0, res);
    return res;

} //2 3                 //0      //empty res array
void dfs(string &s, const string &digits, int pos, vector<string> &res)
{
    int n = digits.size();
    if (pos == n)
    {                     //when have 2 digits
        res.push_back(s); //push
        return;
    }
    for (auto ch : m[digits[pos] - '0'])
    { //m[2] ->abc
        //first ch is
        s += ch;
        dfs(s, digits, pos + 1, res); //after that d(m[3])
        s.pop_back();                 //d is popped back and next iterator will have e
    }
}

int main()
{

    return 0;
}