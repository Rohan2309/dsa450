#include <bits/stdc++.h>
using namespace std;

class Solution
{
    //will return 1 or 0, i is the position we are standing on
    int f(int i, string s, unordered_set<string> &st, vector<int>&dp, int n)
    {
        if (i == n) return 1; //reached end so return true
string tmp; // temporary var
        if (~dp[i])return dp[i];
        for (int j = i; j < n; j++)//start from ith index 
        {
            tmp += s[j];//adding idx by idx in tmp
            if (st.find(tmp) != st.end())// temp is present in dictionary
            {// the next character will be start of the helper 
                if (f(j + 1, s, st,dp,n)) return dp[i] = 1;
            }
        }
        return dp[i] = 0; // if no true
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> st;
        int n = s.size();
        vector<int>dp(n+1,-1);// dp array 
        for (auto a : wordDict)st.insert(a);
        return f(0, s, st,dp,n);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
