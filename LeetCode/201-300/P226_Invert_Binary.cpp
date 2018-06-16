/*
 * https://leetcode.com/problems/invert-binary-tree/description/
 * 反转二叉树
 * 同类题目 P226
 * 
 * 首先反转左子树, 再反转右子树, 再交换根结点的左右孩子
 * 
*/

// #include <iostream>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if( root != NULL ){
			invertTree(root->left);
			invertTree(root->right);
			TreeNode * tmp = root->left;
			root->left = root->right;
			root->right = tmp;
		}
		return root;
	}
};

