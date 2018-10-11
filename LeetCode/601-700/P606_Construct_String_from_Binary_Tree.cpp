/*
https://leetcode.com/problems/construct-string-from-binary-tree/description/
先序遍历一棵树，并给结点值加上括号
同类题目 P609

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
	void pre(TreeNode * root, string & s){
		if( root != NULL ){
			s += to_string(root->val);
			if( root->left == NULL && root->right != NULL ){
				s += "()";
			}else if( root->left != NULL ){
				s += "(";
				pre(root->left, s);
				s += ")";
			}
			
			if( root->right != NULL ){
				s += "(";
				pre(root->right, s);
				s += ")";
			}
		}
	}
	
	string tree2str(TreeNode * root) {
		string ans = "";
		pre(root, ans);
		return ans;
	}
};
