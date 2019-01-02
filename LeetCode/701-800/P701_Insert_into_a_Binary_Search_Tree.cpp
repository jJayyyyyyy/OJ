/*
https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
练习 BST 的插入操作
同类题目 P701

递归和递推的方法都要掌握
*/

#include <iostream>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

struct TreeNode {
int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// 递归
	void rInsertBST(TreeNode * & root, int val){
		if( NULL == root ){
			root = new TreeNode(val);
			return;
		}

		if( val < root->val ){
			rInsertBST(root->left, val);
		}else{
			rInsertBST(root->right, val);
		}
	}

	// 递推
	void nrInsertBST(TreeNode * & root, int val){
		if( root == NULL ){
			root = new TreeNode(val);
			return;
		}

		TreeNode * p = root;
		while( p != NULL ){
			if( p->val > val ){
				if( p->left != NULL ){
					p = p->left;
				}else{
					p->left = new TreeNode(val);
					break;
				}
			}else if( p->val < val ){
				if( p->right != NULL ){
					p = p->right;
				}else{
					p->right = new TreeNode(val);
					break;
				}
			}
		}
	}

	TreeNode* insertIntoBST(TreeNode* root, int val) {
		// rInsertBST(root, val);
		nrInsertBST(root, val);
		return root;
	}
};