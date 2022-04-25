#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->val = data;
        left = NULL;
        right = NULL;
    }
};

int findCeil(TreeNode<int> *root, int x){
    // Write your code here.
	int ans=-1;
	while(root){
		if(x==root->val){
			ans=root->val;
			return ans;
		}
		if(x>root->val){
			root=root->right;
		}
		else{
			ans=root->val;
			root=root->left;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
