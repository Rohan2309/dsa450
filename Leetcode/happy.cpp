/*
202. Happy Number
Easy

3953

598

Add to List

Share
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

 bool isHappy(int n) {
        set<int>s;
        int idx;
        int val;
        while(1){//endless repetations
            val = 0; //reset to 0 avter every loop
            while(n){ //till thhere are digits in n
                idx = n%10; //extracting last digit
                val += idx*idx; //new value
                n/=10; //removing last digit
            }
            
            if(val==1){//valid case, happy number
                return true;
            }
            //invalid case
            else if(s.find(val)!=s.end()){//if we find it in our set, that means the number is beimg repeted
                return false;
            }
            //if we don't find it in set
            s.insert(val);//insert
            n=val;//new n
        }
        return false;
        
    }


int main()
{
    
    return 0;
}