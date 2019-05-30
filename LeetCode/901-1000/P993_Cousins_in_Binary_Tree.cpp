/*
https://leetcode.com/problems/cousins-in-binary-tree/description/
给一棵二叉树, 如果两个结点的深度相同, 且有不同的父结点, 则返回 true, 否则返回 false
注: 每个结点的值不一样
同类题目 P993

思路
遍历结点, 保存子结点值到父结点值的映射, 以及子结点值到深度的映射
*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x){
		val = x;
		left = right = NULL;
	}
};

class Solution {
public:
	vector<int> parentOf, depthOf;

	void preTrav(TreeNode * root){
		if( root != NULL ){
			int valroot = root->val;
			int depthroot = depthOf[valroot];
			TreeNode *left = root->left;
			TreeNode *right = root->right;
			if( left != NULL ){
				int valleft = left->val;
				parentOf[valleft] = valroot;
				depthOf[valleft] = depthroot + 1;
			}
			if( right != NULL ){
				int valright = right->val;
				parentOf[valright] = valroot;
				depthOf[valright] = depthroot + 1;
			}
			preTrav(left);
			preTrav(right);
		}
	}

	bool isCousins(TreeNode* root, int x, int y) {
		parentOf.resize(128, 0);
		depthOf.resize(128, 0);
		preTrav(root);
		return depthOf[x] == depthOf[y] && parentOf[x] != parentOf[y];
	}
};
