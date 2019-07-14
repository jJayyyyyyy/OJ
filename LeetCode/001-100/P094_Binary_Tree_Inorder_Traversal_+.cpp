/*
https://leetcode.com/problems/binary-tree-inorder-traversal/solution/
非递归中序遍历二叉树

同类题目: P094, P145

参考思路:
https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45551/Preorder-Inorder-and-Postorder-Iteratively-Summarization

*/

#include <iostream>
#include <vector>
#include <stack>
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


// 非递归 中序, 前序, 后序 遍历二叉树的模板
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode *> s;
		TreeNode * p = root;

		while( p != NULL || s.size() != 0 ){
			if( p != NULL ){
				s.push(p);
				p = p->left;
			}

			else{
				p = s.top();
				s.pop();
				ans.push_back(p->val);
				p = p->right;
			}
		}

		return ans;
	}

	vector<int> preorderTraversal(TreeNode * root){
		vector<int> ans;
		stack<TreeNode *> s;
		TreeNode * p = root;

		while( p != NULL || s.size() != 0 ){
			if( p != NULL ){
				ans.push_back(p->val);
				s.push(p);
				p = p->left;
			}

			// 此时已经到达子树最左
			else{
				p = s.top();
				s.pop();
				p = p->right;
			}
		}
		return ans;
	}

	vector<int> postorderTraversal(TreeNode * root){
		vector<int> ans;
		stack<TreeNode *> s;
		TreeNode * p = root;

		while( p != NULL || s.size() != 0 ){
			if( p != NULL ){
				ans.push_back(p->val);
				s.push(p);
				p = p->right;
			}

			// 此时已经到达子树最右
			else{
				p = s.top();
				s.pop();
				p = p->left;
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};