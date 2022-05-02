#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}; 

class Solution {
public:
    void dfs(Node *node, Node *copy, vector<Node *> &vis)
    {
        vis[copy->val] = copy;         //we are filling vis arr with it's address
        for (auto x : node->neighbors) //adj
        {
            if (!vis[x->val]) //if not visited
            {
                Node *newNode = new Node(x->val);
                (copy->neighbors).push_back(newNode); // 1->2
                dfs(x, newNode, vis);
            }
            else (copy->neighbors).push_back(vis[x->val]); //pushing pointer
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node)return NULL;
        vector<Node *> vis(1000, NULL);   //visited vec
        Node *copy = new Node(node->val); //copy node
        dfs(node, copy, vis);
        return copy;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
