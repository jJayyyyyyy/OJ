/*
https://leetcode.com/problems/merge-two-binary-trees/description/
合并两棵树
同类题目 P617

思路
以 t1 为基准, 先合并左子树, 再合并右子树, 最后合并根结点
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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
		if( t1 == NULL && t2 == NULL ){
			return NULL;
		}else if( t1 != NULL && t2 == NULL ){
			return t1;
		}else if( t1 == NULL && t2 != NULL ){
			return t2;
		}else{
			t1->left = mergeTrees(t1->left, t2->left);
			t1->right = mergeTrees(t1->right, t2->right);

			t1->val += t2->val;
			return t1;
		}
	}
};