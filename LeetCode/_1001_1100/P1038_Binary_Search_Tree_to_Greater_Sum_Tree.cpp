/*
https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/
BST 逆中序求和
同类题目 P1038

参考思路
*/

#include <iostream>
#include <string>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	void postInTrav( TreeNode * root, int & sum ){
		if( root != NULL ){
			postInTrav(root->right, sum);
			sum += root->val;
			root->val = sum;
			postInTrav(root->left, sum);
		}
	}

	TreeNode* bstToGst(TreeNode* root) {
		int sum = 0;
		postInTrav(root, sum);
		return root;
	}
};
