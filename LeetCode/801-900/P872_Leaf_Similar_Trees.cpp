/*
https://leetcode.com/problems/leaf-similar-trees/description/
判断两棵树的叶子序列是否相同
同类题目 P872

中序遍历
*/


#include <iostream>
using namespace std;

struct TreeNode {
int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	vector<int> v1, v2;

	void inTrav(TreeNode * root, int id){
		if( root != NULL ){
			inTrav(root->left, id);
			if( root->left == NULL && root->right == NULL ){
				if( id == 1 ){
					v1.push_back(root->val);
				}else{
					v2.push_back(root->val);
				}
			}
			inTrav(root->right, id);
		}
	}

	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		inTrav(root1, 1);
		inTrav(root2, 2);
		int len1 = v1.size();
		int len2 = v2.size();
		if( len1 != len2 ){
			return false;
		}else{
			for( int i = 0; i < len1; i++ ){
				if( v1[i] != v2[i] ){
					return false;
				}
			}
			return true;
		}
	}
};
