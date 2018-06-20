/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
给出 BST 的两个结点 p 和 q, 寻找其最近公共祖先
同类题目 P235
 
思路 https://blog.csdn.net/beiyetengqing/article/details/7633651
1.先使 p->val < q.val

2. 查找LCA，分三种情况

* 如果 p 和 q 在 root 的两边，那么 LCA 就是 root
* 如果 p 和 q 在 root 的左边，那么 root = root->left, 再递归
* 如果 p 和 q 在 root 的右边，那么 root = root->right, 再递归

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
	TreeNode(int x)	: val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if( root == NULL || p == NULL || q == NULL ){
			return NULL;
		}

		if( p->val > q->val ){
			swap(p, q);
		}

		if( root->val > p->val && root->val < q->val ){
			return root;
		}else if( root->val == p->val ){
			return p;
		}else if( root->val == q->val ){
			return q;
		}
		// 以上 3 种情况可以归结为 return root
		
		else if( root->val > q->val ){
			return lowestCommonAncestor(root->left, p, q);
		}else if( root->val < p->val ){
			return lowestCommonAncestor(root->right, p, q);
		}
		
	}
};
