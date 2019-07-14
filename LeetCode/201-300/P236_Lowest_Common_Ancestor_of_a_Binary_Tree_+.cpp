/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
求普通二叉树中两个结点的LCA
同类题目 P236, P235

思路
https://github.com/jJayyyyyyy/OJ/blob/master/notes/Question4.md#lca

更简单的方法
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/65375/Very-simple-dfs-c++-solution-only-10-lines
https://blog.csdn.net/u010589524/article/details/82895338
见下
*/

#include <iostream>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q){
		if( root == NULL || root == p || root == q ){
			return root;
		}
		TreeNode * left = lowestCommonAncestor(root->left, p, q);
		TreeNode * right = lowestCommonAncestor(root->right, p, q);
		if( left != NULL && right != NULL ){
			return root;
		}
		else{
			return left==NULL ? right : left;
		}
	}
};

// 美能华面试题, 在求出 LCA 后, 求出两个结点之间的距离
// left = get_dist(lca, p->val, 0)
// right = get_dist(lca, q->val, 0)
// dist = left + right
int get_dist(TreeNode * root, int target, int depth){
	if( root != NULL ){
		if( root->val == target ){
			return depth;
		}
		int left = get_dist(root->left, target, depth + 1);
		int right = get_dist(root->right, target, depth + 1);
		if( left == 0 ){
			return right;
		}
		else{
			return left;
		}
	}
	else{
		return 0;
	}
}