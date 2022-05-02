
/*
28. Implement strStr()
Easy

3741

3516

Add to List

Share
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.size()==0)return 0;
        if(needle.size()>haystack.size())return -1;
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; ++i) {//loop for haystack
            int j ;
            for (j=0; j < n; ++j) {//loop for needle
                if (haystack[i + j] != needle[j]) {//invalid case
                    break;
                }
            }
            if (j == n) {//valid case (when j size is complete)
                return i;//return pos (first index)
            }
        }
        return -1;
    }
};

//KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        //base cases
        if(haystack==needle)return 0;
        if(needle.size()==0)return 0;
        if(needle.size()>haystack.size())return -1;
        int n = needle.size();
        needle+='$';//special character
        needle.append(haystack);
        int m = needle.size();//new string size ll$hello
        
        //KMP
        vector<int>pi(m);//prefix array
        int i=1, j=0;//i start from 1 as 0 will be already 0
        
        while(i<m){
            if(needle[i]==needle[j]){//when string matches
                j++;// value will be greater than prev value
                pi[i]=j;
                i++;//going  to next ele in prefix arr
            }
            else if(j>0){//when does not matches
                j= pi[j-1];//will check prev ele of pre arr till it matches
            }
            else{//when does not matches with any prev ele
                pi[i]=0;
                i++;
            }
        }
        for(int i=0; i<m; ++i){
            if(pi[i]==n){//checking in the prefix array whose val is equal to sz of needle
                return i-(n+1)-(n-1);// modified pos in string
            }
        }
        return -1;
        
    }
};
int main()
{

    return 0;
}