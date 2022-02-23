/*
Power Set 
Easy Accuracy: 48.41% Submissions: 17921 Points: 2
Given a string S find all possible subsequences of the string in lexicographically-sorted order.

Example 1:

Input : str = "abc"
Output: a ab abc ac b bc c
Explanation : There are 7 substrings that 
can be formed from abc.
Example 2:

Input: str = "aa"
Output: a a aa
Explanation : There are 3 substrings that 
can be formed from aa.
Your Task:
You don't need to read ot print anything. Your task is to complete the function AllPossibleStrings() which takes S as input parameter and returns a list of all possible substrings(non-empty) that can be formed from S in lexicographically-sorted order.
 

Expected Time Complexity: O(2n) where n is the length of the string
Expected Space Complexity : O(n * 2n)
 

Constraints: 
1 <= Length of string <= 16
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	//binary of 5 is 101
	//bit index goes from right to left
	//2nd bit of 5 is set (& operator with 1) if not 0 then set
	//(n&(1<<i))!=0 then set bit    1<<2 = 100
	//string abc has 3 guys so idxing will be 0 1 2
	//2^3 = 8 so we have elements from 0 to 7(2^n-1), we get binary of every element
	//0 means niot picking in substr and 1 means picking
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    //1<<n is 2^n
		    int n = s.length();
		    vector<string>ans;
		    for(int i=0; i<(1<<n);++i){//checking nums from 0 to 7, which is 2^n
		        string sub="";
		        for(int j=0; j<n;++j){//picking not picking, checkiung binary of each digit
		            if(i & (1<<j)){//if set bit
		                sub+=s[j];//we pick
		            }
		        }
		        if(sub.size()>0)ans.emplace_back(sub);
		    }
		    sort(ans.begin(),ans.end());//lexicographically sorted
		    return ans;
		}
};

int main()
{
	return 0;
}