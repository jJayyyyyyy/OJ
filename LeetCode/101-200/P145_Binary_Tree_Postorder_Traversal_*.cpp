/*
https://leetcode.com/problems/binary-tree-postorder-traversal/description/
实现二叉树的后序遍历

同类题目 P145, P094

plus:
非递归方式实现后序遍历
思路:
https://leetcode.com/problems/binary-tree-postorder-traversal/solution/


非递归遍历总结:
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


class Solution {
public:
	vector<int> ans;

	void postTrav(TreeNode * root){
		if( root != NULL ){
			postTrav(root->left);
			postTrav(root->right);
			ans.push_back(root->val);
		}
	}

	vector<int> postorderTraversal(TreeNode* root) {
		postTrav(root);
		return ans;
	}
};

// 先 DRL, 再翻转 ans
class Solution2 {
public:
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