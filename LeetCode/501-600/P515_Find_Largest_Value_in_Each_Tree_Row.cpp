/*
https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
层序遍历，找到每一行的最大值
同类题目 P513, P515

如果题目定义的结构体中不包含 level
如何在层序遍历的时候判断行尾！

两层循环
while( q.size() ){
	size_t size = q.size();
	
	while( size > 0 ){
		TreeNode * node = q.front();
		// vis q
		q.pop();
		size--;

		if( node->left != NULL ){
			q.push(node->left);
		}
		if( node->right != NULL ){
			q.push(node->right);
		}
	}
}

参考
https://leetcode.com/problems/find-bottom-left-tree-value/discuss/98784/BFS-and-DFS-Solutions
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	int findBottomLeftValue(TreeNode * root){
		queue<TreeNode *> q;
		q.push(root);
		int ans = 0;
		while( q.size() ){
			size_t size = q.size();
			ans = q.front()->val;
			while( size > 0 ){
				TreeNode * node = q.front();
				// vis q
				q.pop();
				size--;

				if( node->left != NULL ){
					q.push(node->left);
				}
				if( node->right != NULL ){
					q.push(node->right);
				}
			}
		}
		return ans;
	}
};