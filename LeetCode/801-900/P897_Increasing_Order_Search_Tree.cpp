/*
https://leetcode.com/problems/increasing-order-search-tree/description/
重新排列一棵树(BST), 新的树只有右孩子, 新树从根到叶的结点的顺序是原树的中序遍历结果。
同类题目 P897
*/


#include <iostream>
#include <vector>
using namespace std;

static int ioSpeedUp=[](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int v){
		val = v;
		left = right = NULL;
	}
};

class Solution {
public:
	TreeNode *newRoot, *p;

	void inTrav(TreeNode * root){
		if( root != NULL ){
			inTrav(root->left);
			if( newRoot == NULL ){
				newRoot = root;
				p = newRoot;
			}else{
				p->right = root;
				p = p->right;
				// 注意此时root的左子树已经走完了，要将其置为NULL
				// 否则会形成一个闭环
				// OJ将无法遍历新的树
				root->left = NULL;
			}
			inTrav(root->right);
		}
	}

	TreeNode * increasingBST(TreeNode * root) {
		if( root == NULL ){
			return root;
		}
		newRoot = p = NULL;
		inTrav(root);
		return newRoot;
	}
};

int main(){
	Solution s;
	TreeNode * root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	s.increasingBST(root);
	return 0;
}
