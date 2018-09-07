/*
https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
求一棵n叉树的最大深度
同类题目 P559

*/

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
	int val;
	vector<Node *> children;

	Node(){}

	TreeNode(int _val, vector<Node *> _children){
		val = _val;
		children = _children;
	}
};

class Solution{
public:
	void dfs(Node * root, int curDepth, int & maxDepth){
		if( root != NULL ){
			maxDepth = max(curDepth, maxDepth);
			for( auto child : root->children ){
				dfs( child, curDepth + 1, maxDepth );
			}
		}
	}

	int maxDepth(Node * root) {
		if( root == NULL ){
			return 0;
		}

		int curDepth = 1, maxDepth = 1;
		dfs(root, curDepth, maxDepth);
		return maxDepth;
	}
};
