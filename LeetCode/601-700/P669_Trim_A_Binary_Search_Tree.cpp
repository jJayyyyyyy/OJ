/*
https://leetcode.com/problems/trim-a-binary-search-tree/description/
修剪一棵BST
同类题目 P669, P450

参考思路
https://leetcode.com/problems/trim-a-binary-search-tree/solution/

先找出左孩子 left, 右孩子 right

如果当前子树的根节点的值 root->val 不在 [L, R] 的范围里面，则返回左孩子或者右孩子
if( root->val < L ){
	return right;
}
if( root->val > R ){
	return left;
}


否则，进行
root->left = left;
root->right = right;

再返回 根结点 root
return root;

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

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution{
public:
	TreeNode * trimBST(TreeNode* root, int L, int R) {
		if( root == NULL ){
			return NULL;
		}
		TreeNode * left = trimBST(root->left, L, R);
		TreeNode * right = trimBST(root->right, L, R);

		if( root->val < L ){
			return right;
		}
		if( root->val > R ){
			return left;
		}

		root->left = left;
		root->right = right;
		return root;
	}
};