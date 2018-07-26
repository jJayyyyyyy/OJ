/*
https://leetcode.com/problems/sum-of-left-leaves/description/
找到所有的左叶结点, 进行值的求和
同类题目 P412

*/

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int ans;

	bool isLeaf(TreeNode * root){
		return root->left == NULL && root->right == NULL;
	}

	void preTrav(TreeNode * root){
		if( root != NULL ){
			if( root->left != NULL && isLeaf(root->left) ){
				ans += root->left->val;
			}
			preTrav(root->left);
			preTrav(root->right);
		}
	}

	int sumOfLeftLeaves(TreeNode* root) {
		ans = 0;
		preTrav(root);
		return ans;
	}
};