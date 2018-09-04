/*
https://leetcode.com/problems/diameter-of-binary-tree/description/
树的直径定义为 max(d[i, j])
其中 d[i, j] 表示结点 i 和结点 j 之间的距离
给定一棵树，求其直径
同类题目 P543

注意:
直径不必经过根节点

若要求必须经过根结点，那么就变成了 SolutionThroughRoot
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 不必经过root
class Solution{
public:
	int dfs(TreeNode * root, int & ans){
		if(root == NULL){
			return 0;
		}
		int lHeight = dfs(root->left, ans);		// 左子树高度
		int rHeight = dfs(root->right, ans);	// 右子树高度

		ans = max(ans, lHeight + rHeight);		// 左右子树高度相加, 若大于当前直径则更新ans
		return max(lHeight, rHeight) + 1;		// 根的高度
	}

	int diameterOfBinaryTree(TreeNode * root){
		int ans = 0;
		dfs(root, ans);
		return ans;
	}
};


// 若必须经过根结点, 那就是 左子树的高度 + 右子树的高度
class SolutionThroughRoot{
public:
	int dfs(TreeNode * root){
		if(root == NULL){
			return 0;
		}
		int lH = dfs(root->left);
		int rH = dfs(root->right);
		return max(lH, rH) + 1;
	}

	int diameterOfBinaryTree(TreeNode * root){
		if( root == NULL ){
			return 0;
		}
		return dfs(root->left) + dfs(root->right);
	}
};
