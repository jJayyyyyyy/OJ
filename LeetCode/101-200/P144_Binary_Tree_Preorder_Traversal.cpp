/*
https://leetcode.com/problems/binary-tree-preorder-traversal/description/
给定一个链表, 问这个链表是不是循环链表
同类题目 P141, P589
*/

#include <iostream>
#include <vector>
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
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	vector<int> ans;

	void pre(TreeNode * root){
		if( root != NULL ){
			ans.push_back(root->val);
			pre(root->left);
			pre(root->right);
		}
	}

	vector<int> preorderTraversal(TreeNode* root) {
		pre(root);
		return ans;
	}
};

// 非递归实现
// 参考: https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/45266/Accepted-iterative-solution-in-Java-using-stack.
class Solution2{
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode *> s;

		while( root != NULL ){
			ans.push_back(root);
			if( root->right != NULL ){
				s.push(root->right);
			}
			root = root->left;
			if( root == NULL && s.size() > 0 ){
				root = s.top();
				s.pop();
			}
		}
		
		return ans;
	}
}