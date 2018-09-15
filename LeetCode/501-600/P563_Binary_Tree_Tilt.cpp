/*
https://leetcode.com/problems/binary-tree-tilt/description/
tilt定义如下
sumLeft = (sum of all node val in the left child tree), ∑(left->val)
sumRight = (sum of all node val in the right child tree), ∑(right->val)
Tilt(node) = abs(sumLeft - sumRight)
Tilt(tree) = (sum of all Tilt(node) ), ∑( Tilt(node[i]) )
求一棵树的 Tilt
同类题目 P563

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution{
public:
	int sumT;

	int findSubSum(TreeNode * root){
		if( root == NULL ){
			return 0;
		}else{
			int sumLeft = findSubSum(root->left);
			int sumRight = findSubSum(root->right);

			int sumRoot = root->val + sumLeft + sumRight;
			int rootT = abs(sumLeft - sumRight);
			sumT += rootT;
			return sumRoot;
		}
	}

	int findTilt(TreeNode * root){
		if( root == NULL ){
			return 0;
		}else{
			sumT = 0;
			findSubSum(root);
			return sumT;
		}
	}
};