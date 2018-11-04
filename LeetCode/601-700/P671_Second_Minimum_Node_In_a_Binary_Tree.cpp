/*
https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
遍历树，返回第二小的结点的值
同类题目 P671

*/

#include <iostream>
using namespace std;

struct TreeNode{
	TreeNode *left, *right;
	int val;
	TreeNode(int v){
		val = v;
		left = right = NULL;
	}
};

class Solution{
public:
	unsigned int firstMin, secondMin;
	
	void preTrav(TreeNode * root){
		if( root != NULL ){
			if( root->val <= firstMin ){
				firstMin = root->val;
			}else if( root->val <= secondMin ){
				secondMin = root->val;
			}
			preTrav(root->left);
			preTrav(root->right);
		}
	}
	
	int findSecondMinimumValue(TreeNode * root){
		if( root == NULL ){
			return -1;
		}
		firstMin = secondMin = 0xffffffff;
		preTrav(root);
		if( secondMin == 0xffffffff ){
			return -1;
		}else{
			return secondMin;
		}
	}
};

int main() {
// TreeNode * root = new TreeNode(2);
// root->left = new TreeNode(2);
// root->right = new TreeNode(5);
// root->right->left = new TreeNode(5);
// root->right->right = new TreeNode(7);

	TreeNode * root = new TreeNode(5);
	root->left = new TreeNode(8);
	root->right = new TreeNode(5);
	Solution s;
	s.findSecondMinimumValue(root);
	
	return 0;
}
