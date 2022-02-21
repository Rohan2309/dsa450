/*

Implement Trie ll
Difficulty: MEDIUM
Contributed By
Sounak Majumder
|
Level 1
Avg. time to solve
30 min
Success Rate
70%
Problem Statement
Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.
1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5) erase(“WORD”): Ninja has to delete this string “WORD” from the “TRIE”.
Note:
1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.
Can you help Ninja implement the "TRIE" data structure?
Input Format:
The first line contains a single integer “T” representing the number of test cases. 

The first line of each test case will contain a single integer “N” which denotes how many times the functions(as discussed above) will be called.

The next “N” lines contain the two space-separated strings, the first one is the name of the function and the second one is a “WORD”.
Output Format:
For each test case, complete all the functions as we discussed above.

The output for every test case will be printed in a separate line.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= “T” <= 50
1 <= “N” <= 10000
 “WORD” = {a to z}
1 <= | “WORD” | <= 1000

Where “T” is the number of test cases, “N” denotes how many times the functions(as discussed above) we call, “WORD” denotes the string on which we have to perform all the operations as we discussed above, and | “WORD” | denotes the length of the string “WORD”.

Time limit: 1 sec.
Sample Input 1:
1
5
insert coding
insert ninja
countWordsEqualTo coding
countWordsStartingWith nin
erase coding
Sample Output 1:
1
1   
Explanation Of Sample Input 1:
After insertion of “coding” in “TRIE”:

After insertion of “ninja” in “TRIE”:

Count words equal to “coding” :

Count words those prefix is “nin”:

After deletion of the word “coding”, “TRIE” is:

Sample Input 2:
1
6
insert samsung
insert samsung
insert vivo
erase vivo
countWordsEqualTo samsung
countWordsStartingWith vi
Sample Output 2:
2
0
Explanation For Sample Input 2:
insert “samsung”: we are going to insert the word “samsung” into the “TRIE”.

insert “iphone”: we are going to insert another “samsung” word into the “TRIE”.

insert “vivo”: we are going to insert the word “vivo” into the “TRIE”.

erase “vivo”: we are going to delete the word “vivo” from the “TRIE”.

countWordsEqualTo “samsung”: There are two instances of “sumsung” is present in “TRIE”.

countWordsStartingWith “vi”: There is not a single word in the “TRIE” that starts from the prefix “vi”
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];//for every char there will be ref link
    int cntEnd=0;//count end with
    int cntPre=0;//count prefix
    //char exists in trie or not
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
    //whenever we reach the end we need to incre the countEnd
    void increEnd(){
        cntEnd++;
    }
    //incre prefix everytime
    void increPre(){
        cntPre++;
    }
    
    //del
    void delEnd(){
        cntEnd--;
    }
    void reducePre(){
        cntPre--;
    }
    
    
    //get no. counts
    int getEnd(){
        return cntEnd;
    }
    int getPre(){
        return cntPre;
    }
};
class Trie{
private: 
    Node* root;//initially every trie will have a root
    public:

    Trie(){
        // Write your code here.
        //constructor
        root = new Node();//new obj for this particular class itself
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root; //dummy var node initially pointing to the root
        for(int i=0; i<word.size(); ++i){
            if(!(node->containsKey(word[i]))){//if this node is empty we will create it
                node->put(word[i], new Node());//creating reference
            }
            //moving to the refernce trie
            node=node->get(word[i]);//advanced it , so that we can insert the next character
            //icreasing the prefix for that ref trie, after we have adv to that
            node->increPre();
        }
        //we are at the end
        node->increEnd();//increases end
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root; //dummy var node initially pointing to the root 
        for(int i=0; i<word.size();++i){
            if(node->containsKey(word[i])){//if the word is there
                node=node->get(word[i]);//moving to that word
            }
            else{//if we don't have that char
                return 0;//it will return 0
            }
        }
        //if we have reached the end
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
         Node* node = root; //dummy var node initially pointing to the root 
        for(int i=0; i<word.size();++i){
            if(node->containsKey(word[i])){//if the word is there
                node=node->get(word[i]);//moving to that word
            }
            else{//if we don't have that char
                return 0;//it will return 0
            }
        }
        //how many are there
        return node->getPre();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root; //dummy var node initially pointing to the root 
        for(int i=0; i<word.size();++i){
            if(node->containsKey(word[i])){//if the word is there
                node=node->get(word[i]);//moving to that word
                node->reducePre();//reducing prefix
            }
            else{//if we don't have that char
                return;
            }
        }
        node->delEnd();//at the end we will delete the end count
    }
};


int main()
{
	return 0;
}