/*

208. Implement Trie (Prefix Tree)
Medium

6519

87

Add to List

Share
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];//for every char there will be ref link
    bool flag = false;//end of word
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
    //marking end of word
    void setEnd(){
        flag=true;
    }
    //checking word ended or not
    bool isEnd(){
        return flag;
    }
};
class Trie {
private: 
    Node* root;//initially every trie will have a root
public:
    Trie() {
        root = new Node();//new obj for this particular class itself
    }
    
    void insert(string word) {
        Node* node = root; //dummy var node initially pointing to the root
        for(int i=0; i<word.size(); ++i){
            if(!(node->containsKey(word[i]))){//if this node is empty we will create it
                node->put(word[i], new Node());//creating reference
            }
            //moving to the refernce trie
            node=node->get(word[i]);//advanced it , so that we can insert the next character
        }
        //now all letters are inserted
        node->setEnd();//insertion finished
    }
    
    bool search(string word) {
        Node* node = root; //dummy var node initially pointing to the root
        for(int i=0; i<word.size(); ++i){
            if(!(node->containsKey(word[i]))){//if this node is empty we will return false
                return false;
            }
            //if contains
            node = node->get(word[i]);//get that and move accross, going to ref
        }
        return node->isEnd();//if isend is true, it will return true
    }
    
    bool startsWith(string prefix) {
        Node* node = root; //dummy var node initially pointing to the root
        for(int i=0; i<prefix.size(); ++i){
            if(!(node->containsKey(prefix[i]))){//if this node is empty we will return false
                return false;
            }
            //if contains
            node = node->get(prefix[i]);//get that and move accross, going to ref
        }
        return true;//if all words are found it return true
    }
};

int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}