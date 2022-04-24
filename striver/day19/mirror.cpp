#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(!node)return;
        mirror(node->left);//going to extremes
        mirror(node->right);
        swap(node->left,node->right);//swapping values from last to first
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
