/*
22. Generate Parentheses
Medium

9611

385

Add to List

Share
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/

#include <bits/stdc++.h>
using namespace std;

void func(vector<string> &ans, int n, int open, int close, string curStr)
{
    //base condition
    int m = n * 2; //have same number of both opening and closing brackets
    if (curStr.size() == m)
    {
        ans.push_back(curStr); //when we have same m then we pushback into answer
        return;                //backstrack
    }
    if (open < n)
    { //cond for opening brack
        func(ans, n, open + 1, close, curStr + "(");
    }
    if (close < open)
    { //cond for closing brack
        func(ans, n, open, close + 1, curStr + ")");
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    func(ans, n, 0, 0, ""); //initial no of opening and closing bracks and initial empty string
    return ans;
}
int main()
{

    return 0;
}