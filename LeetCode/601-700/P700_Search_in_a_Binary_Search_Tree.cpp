/*
https://leetcode.com/problems/search-in-a-binary-search-tree/description/
在BST中搜索结点
同类题目 P700
*/

#include <iostream>
using namespace std;

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
	TreeNode* searchBST(TreeNode* root, int val) {
		if( root == NULL ){
			return root;
		}else{
			if( val < root->val ){
				return searchBST(root->left, val);
			}else if( val > root->val ){
				return searchBST(root->right, val);
			}else{
				return root;
			}
		}
	}
};
