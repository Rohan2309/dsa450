#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    
};

class Solution {
    private:
        queue<pair<Node*,int>>q;//root and level
        map<int,int>mp;//level and root value
        vector<int>ans;
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if(!root)return ans;
        q.push({root,0});//first root at centre so level is 0
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int lvl = it.second;
            mp[lvl] = node->data;//updating map with last value of level
            if(node->left)q.push({node->left,lvl-1});//when we go left level decreases
            if(node->right)q.push({node->right,lvl+1});//right level increases
        }
        for(auto it: mp)ans.push_back(it.second);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
