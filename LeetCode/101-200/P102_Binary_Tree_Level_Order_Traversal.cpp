/*
https://leetcode.com/problems/binary-tree-level-order-traversal/description/
层序遍历
同类题目 P102, P104, P107
*/

#include <iostream>
#include <queue>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x)	: val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	vector< vector<int> > levelOrder(TreeNode * root) {
		vector< vector<int> > ans;
		if( root == NULL ){
			return ans;
		}

		queue<TreeNode *> q;
		q.push(root);

		while( q.size() ){
			int len = q.size();
			vector<int> level;
			for( int i = 0; i < len; i++ ){
				TreeNode * node = q.front();
				// vis node
				level.push_back(node->val);
				q.pop();
				if( node->left != NULL ){
					q.push(node->left);
				}
				if( node->right != NULL ){
					q.push(node->right);
				}
			}
			ans.push_back(level);
		}
		return ans;
	}
};

