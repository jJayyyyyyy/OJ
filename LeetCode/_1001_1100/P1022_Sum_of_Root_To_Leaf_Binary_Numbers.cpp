/*
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
树的遍历
同类题目 P1022
*/

#include <iostream>
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
	int sum;

	void preTrav(TreeNode * root, int num){
		if( root != NULL ){
			num = (num << 1) + root->val;
			if( root->left == NULL && root->right == NULL ){
				sum += num;
			}else{
				preTrav(root->left, num);
				preTrav(root->right, num);
			}
		}
	}

	int sumRootToLeaf(TreeNode* root) {
		sum = 0;
		preTrav(root, 0);
		return sum;
	}
};

int main(){
	Solution s;
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(0);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(1);

	int sum = s.sumRootToLeaf(root);
}
