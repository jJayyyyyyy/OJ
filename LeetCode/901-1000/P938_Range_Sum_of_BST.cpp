/*
https://leetcode.com/problems/range-sum-of-bst/description/
输入 BST, 求值在 [L, R] 范围内的所有结点的值的和
同类题目 P938
*/

#include <iostream>
using namespace std;

struct TreeNode {
int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	int sum;

	void inOrder(TreeNode * root, int L, int R){
		if( root != NULL ){
			inOrder(root->left, L, R);
			int val = root->val;
			if( L <= val && val <= R ){
				sum += val;
			}
			inOrder(root->right, L, R);
		}
	}

	int rangeSumBST(TreeNode* root, int L, int R) {
		sum = 0;
		inOrder(root, L, R);
		return sum;
	}
};
