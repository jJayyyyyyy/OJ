/*
https://leetcode.com/problems/univalued-binary-tree/description/
判断一棵树的所有结点的值是否相同
同类题目 P965
*/

#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	unordered_set<int> s;

	void inTrav(TreeNode * root){
		if( root != NULL ){
			inTrav(root->left);
			s.insert(root->val);
			inTrav(root->right);
		}
	}

	bool isUnivalTree(TreeNode* root) {
		inTrav(root);
		return s.size() == 1;
	}
};