/*
Number Of Distinct Substring
Difficulty: MEDIUM
Contributed By
Ankit Kharb
|
Level 1
Avg. time to solve
30 min
Success Rate
70%
Problem Statement
Ninja has been given a string ‘WORD’ containing lowercase English alphabets having length ‘N’. Ninja wants to calculate the number of distinct substrings in the ‘WORD’.
For Example :
For ‘WORD’ = “abcd” and ‘N’ = 4 following are the 10 distinct substrings of ‘WORD’.
“abcd”, “abc”, “ab”, “a”, “bcd”, “bc”, “b”, “cd”, “c”, and “d”
Can you help the Ninja to find out the number of distinct substrings in the ‘WORD’?
Note :
If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.
Input Format :
The first line of input contains an integer 'T' representing the number of test cases. Then the test cases follow.

The first line of each test case contains an integer ‘N’ representing the length of the string ‘WORD’.

The second line of each test case contains the string ‘WORD’.
Output Format :
For each test case, print the number of distinct substrings in the ‘WORD’

The output for each test case is printed in a separate line.
Constraints :
1 <= T <= 100
1 <= N <= 10 ^ 3
‘a’ <= WORD[i] <= ‘z’

Where ‘WORD[i]’ denotes the element at position ‘i’ in 'WORD'.

Time Limit: 1 sec
Sample Input 1 :
2
3
aaa
4
abab
Sample Output 1 :
3
7
Explanation For Sample Output 1 :
For the first test case :
Following are distinct substrings of the given string ‘WORD’.
“aaa”
“aa”   
“a”

For the second test case :
Following are distinct substrings of the given string ‘WORD’.
“abab”
“aba” 
“ab”
“a”
“bab”
“ba”
“b”
Sample Input 2 :
2
1
z
3
abc    
Sample Output 2 :
1
6
Explanation For Sample Output 2:
For the first test case:
There is only one possible substring of the given string ‘WORD’ which is also distinct so the answer will be 1.

For the second test case :
Following are distinct substrings of the given string ‘WORD’.
“abc”
“ab”
“a”
“bc”
“b”
“c”
*/

#include<bits/stdc++.h>
using namespace std;
//if str exists in trie we wont count
//if str does not exists we insert and cnt
struct Node{
    Node *links[26];//for every char there will be ref link
    bool containsKey(char c){
        return (links[c-'a']!=NULL);//does exists
    }
    //for creating link
    void put(char c, Node* node){//new node to put and char c
        links[c-'a']=node;//for this char the ref node is node
        //apple's a will be pointing to a new trie
    }
    //moving to the reference
    Node* get(char c){
        return links[c-'a'];//where that char is pointing to
    }
};


int distinctSubstring(string &word) {
    //  Write your code here.
    int ans=0;
    int n = word.size();
    Node* root= new Node();//initially every trie will have a root
    for(int i=0; i<n; ++i){
        Node* node = root;//we have a node = root, as we start from root
        for(int j=i; j<n; ++j){
          if(!(node->containsKey(word[j]))){//if this node is empty we will create it
              ans++;//incre counter
              node->put(word[j], new Node());//creating reference
            }
            //moving to the refernce trie
            node=node->get(word[j]);//advanced it , so that we can insert the next character  
        }
            
        }
    return ans;
}


int main()
{
	return 0;
}