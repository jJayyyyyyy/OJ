/*
https://leetcode.com/problems/binary-tree-pruning/description/
为一棵二叉树剪枝, 如果子树中不包含值为 1 的结点, 那么就扔掉这棵子树
同类题目 P814
*/

#include <iostream>
#include <vector>
using namespace std;

static int ioSpeedUp=[](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int v){
		val = v;
		left = right = NULL;
	}
};

class Solution {
public:
	int preOrder(TreeNode * root){
		int ans;
		if( root != NULL ){
			int left = preOrder(root->left);
			int right = preOrder(root->right);
			ans = root->val || left || right;

			if( left == 0 ){
				root->left = NULL;
			}
			if( right == 0 ){
				root->right = NULL;
			}
		}
		else{
			ans = 0;
		}
		return ans;
	}

	TreeNode* pruneTree(TreeNode* root) {
		preOrder(root);
		return root;
	}
};