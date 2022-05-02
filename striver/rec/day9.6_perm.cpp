/*
60. Permutation Sequence
Hard

3340

388

Add to List

Share
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public://initially when n = 4, k=17 (but for 0 based indexing we reduce it by 1 ,,so k==16)
    //n!=24,,,24/4=6,,,,so 4 blocks of 6(which is n-1 fact)
    //where 16 lies,,,16 lies in the 3rd block(k=16/6=2),,,,so 3 is the 1st digit,,,16%6=4
    //now we have 3 digits left ={1,2,4}
    //we have 3 blocks of 2...(k=4/2=2)..so 4 will lie in the 3rd block that is 4,,,4%2=0
    //now we have 2 digits left 1 and 2,,,then k will be 0, we pick 1
    //then k will again be 0 we pick up 1
    string getPermutation(int n, int k) {
        //storing all the numbers in vector {1,2,3,4}
        //computing (n-1)!==3!==6
        int fact = 1; 
        vector<int> V; 
        for(int i = 1;i<n;i++) {
            fact = fact * i; 
            V.emplace_back(i); 
        }
        V.emplace_back(n); //pushing 4
        string ans = ""; //answer to be returned
        k = k - 1; //as 0 based indexing so 17->16
        while(true) {
             //calculating 16/6-->2
            //v[2] = 3, 3 is the 1st number
            ans += to_string(V[k / fact]); //converting to string
            V.erase(V.begin() + k / fact); //removing 3 from ds
            if(V.size() == 0)break;//till ds becomes empty
            k %= fact; //next val of k (16%6-->4) new k = 4
            fact /= V.size();//next val of fact (16/6-->2) new fact = 2
        }
        return ans;

    }
};
int main()
{
    
    return 0;
}