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

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
