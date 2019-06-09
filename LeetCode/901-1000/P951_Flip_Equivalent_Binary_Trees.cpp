/*
https://leetcode.com/problems/flip-equivalent-binary-trees/description/
判断二叉树 root1 经过若干次翻转后得到能否变成 root2
翻转的意思是, 子树根不变, 左右孩子交换
同类题目 P951

注意, 不必完全翻转
也就是说, 如果两棵树完全相同, 那么这也是一个 flipEquiv
*/

#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		if( root1 == NULL && root2 == NULL ){
			return true;
		}
		else if( root1 != NULL && root2 == NULL ){
			return false;
		}
		else if( root1 == NULL && root2 != NULL ){
			return false;
		}
		else{
			if( root1->val != root2->val ){
				return false;
			}
			else{
				return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left) || flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
			}
		}
	}
};
