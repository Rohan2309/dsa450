#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void f(TreeNode * root){
	if(!root)return;//base
	int child = 0;//for having sum of both children
	if(root->left)child+=root->left->data;
	if(root->right)child+=root->right->data;
	if(child<root->data)root->data=child;//if root is smaller than sum, make it equal to sum
	else{//if root is bigger than sum of child, each child will hae root's value
		if(root->left)root->left->data=root->data;
		if(root->right)root->right->data=root->data;
	}
	//move to the left ans right
	f(root->left);
	f(root->right);
	//when coming back
	int total = 0;//for having sum of both children
	if(root->left)total+=root->left->data;
	if(root->right)total+=root->right->data;
	//assign it to the root, while coming back (if it's not a leaf)
	if(root->left or root->right)root->data=total;
}
void changeTree(TreeNode  * root) {
    // Write your code here.
	f(root);
}  

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
