/*
146. LRU Cache
Medium

12393

486

Add to List

Share
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
class node{ //defining node for DLL
    public:
    int key;
    int val;
    node* next;
    node* prev;
    node(int _key, int _val){ //constructor
        key = _key;
        val = _val;
    }
};
//dummy values
node* head = new node(-1,-1);
node* tail = new node(-1,-1);

int cap;//capacity(total size)

//hashmap
unordered_map<int, node*>m; // will have value with node address
    LRUCache(int capacity) {
        cap = capacity; //assigning
        head->next = tail;
        tail->prev = head;
    }
    //initial configurations are ready.
    

    void addNode(node* newNode){
         //added right after head
         node* temp = head->next; //temp node after head

         //inserting newNode between head and temp
         newNode->next = temp;
         newNode->prev = head;
         head->next = newNode;
         temp->prev = newNode;

    }

    void deleteNode(node* delNode){
        node* delPrev = delNode->prev; //creating a node before target node
        node* delNext = delNode->next; //creating a node after target node

        //connecting both
        delPrev->next = delNext; 
        delNext->prev = delPrev;
    }

    int get(int key_) {
        if(m.find(key_)!=m.end()){//if key already exists in hashmap
             node* addr = m[key_]; //we are taking the node's address
             int ans = addr->val; //taking the value of that node, from DLL
             m.erase(key_); //erasing as it consists old address.
             deleteNode(addr); //deleting node from DLL
             addNode(addr);//adding node after head, so it is most recently used
             m[key_] = head->next; // new address (as the new element is next to head)
             return ans;
        }
        return -1;//if not found
    }
    
    void put(int key_, int value) {
        if(m.find(key_)!=m.end()){ 
            //if key already exists in hash map
            node* nodeAddr = m[key_]; //getting node address, wherever it existed
            m.erase(key_); //take it out from that position
            deleteNode(nodeAddr); //as it is the last frequently used
        }
        if(m.size()==cap){ 
            //if size is full
            m.erase(tail->prev->key);//removing least frequently used from hashmap
            deleteNode(tail->prev);
        }

        //insert it right after head
        addNode(new node(key_, value));
        m[key_]= head->next; //assigning new address value
    }
};
int main()
{

    return 0;
}