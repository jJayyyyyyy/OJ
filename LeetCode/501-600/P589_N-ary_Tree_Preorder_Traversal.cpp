/*
https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
给定一棵 N 叉树，返回其后序遍历序列
同类题目 P590, P589, P144
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int val;
	vector<Node *> children;
	Node() {}
	Node (int _val, vector<Node *> _children){
		val = _val;
		children = _children;
	}
};

class Solution{
public:
	vector<int> ans;

	void pre(Node * root){
		if( root != NULL ){
			for( Node * child : root->children ){
				pre(child);
			}
			ans.push_back(root->val);
		}
	}

	vector<int> preorder(Node * root) {
		pre(root);
		return ans;
	}
};
