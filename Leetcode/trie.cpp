/*
208. Implement Trie (Prefix Tree)
Medium

5742

82

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

#include <bits/stdc++.h>
using namespace std;

class Trie
{
    //member vars
    Trie *children[26]; //pointer, as a-z
    bool isEndOfWord;

public:
    Trie()
    {
        isEndOfWord = false; //default value
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr; //every children is null
        }
    }

    void insert(string word)
    {
        Trie *curr = this; //root
        for (char c : word)
        {
            if (!(curr->children[c - 'a']))
            { //if this node is empty we will create it
                curr->children[c - 'a'] = new Trie;
            }
            curr = curr->children[c - 'a']; //advanced it , so that we can insert the next character
        }
        //now all letters are inserted
        curr->isEndOfWord = true; //insertion finished
    }

    bool search(string word)
    {
        Trie *curr = this; //root
        for (char c : word)
        {
            curr = curr->children[c - 'a'];
            if (!curr)
            { //if this node is empty we will return false
                return false;
            }
        }
        if (curr->isEndOfWord)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool startsWith(string prefix)
    {
        Trie *curr = this; //root
        for (char c : prefix)
        {
            curr = curr->children[c - 'a'];
            if (!curr)
            { //if this node is empty we will return false
                return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}