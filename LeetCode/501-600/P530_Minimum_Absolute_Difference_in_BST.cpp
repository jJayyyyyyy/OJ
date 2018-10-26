/*
https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
给定BST, 求 min( abs(v[i] - v[j]) ). 注意, 本题中的结点非负
同类题目 P530, P783
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
	int preVal = -1;
	int ans = 0x3fffffff;

	void inTrav(TreeNode * root){
		if( root != NULL ){
			inTrav(root->left);
			if( preVal != -1 ){
				int nowVal = root->val;
				ans = min(ans, nowVal - preVal);
			}
			preVal = root->val;
			inTrav(root->right);
		}
	}

	// there are at least two nodes in the BST
	int getMinimumDifference(TreeNode * root) {
		inTrav(root);
		return ans;
	}
};

