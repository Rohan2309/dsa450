/*
151. Reverse Words in a String
Medium

2893

3802

Add to List

Share
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res,tmp;
        int j;//end of word
        int i=0;//beginning of word
        while(i<n){
            while (i<n and s[i]==' ')++i;//del leading spaces
            if(i>=n)break;//will go out of loop
            j=i+1;//will be next ele of i
            while(j<n and s[j]!=' ')++j;//will reach end of word
            tmp = s.substr(i,j-i);//gettting that word
            if(res.size()==0)res=tmp;//when result is empty we just add temp
            else res=tmp+" "+res;//when not empty we add in front
            i=j+1;//advancing i to next
        }
        return res;

        
    }
};

int main()
{

    return 0;
}