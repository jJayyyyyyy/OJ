/*
 * https://leetcode.com/problems/same-tree/description/
 * 判断两棵树是否相同
 * 同类题目 P100, P101
 * 注意, PAT的这类题目, 各个结点的值一般是不同的, 因此可以用 pre, in 序列是否分别相同来判断两棵树是否相同
 * 然而LeetCode与PAT不同, 本题的输入样例告诉我们, 一棵树中两个结点的值可能是相同的
 * [1, 1]
 * [1, NULL, 1]
 * 这样, 他们的 pre 序列相同, in 序列也相同, 此时无法判断树形
 * 因此需要从 p 和 q 的根开始, 同时向下探索
 * 最简单的方法是递归
 * 先判断是否为空结点, if( p == NULL && q == NULL )
 * 然后判断根结点是否相同, 左孩子是否相同, 右孩子是否相同
 * return ( p->val == q->val ) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)
 *
*/

// #include <iostream>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

// struct TreeNode{
// 	int val;
// 	TreeNode *left, *right;
// 	TreeNode(int x)	: val(x), left(NULL), right(NULL) {}
// };


class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q){
		if( p == NULL && q == NULL ){
			return true;
		}else if( p != NULL && q == NULL ){
			return false;
		}else if( p == NULL && q != NULL ){
			return false;
		}else{
			return ( p->val == q->val ) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
	}
};


// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;


// 	TreeNode *p = NULL, *q = NULL;
// 	cout<<s.isSameTree(p, q)<<'\n';	// 1

// 	p = new TreeNode(1);
// 	cout<<s.isSameTree(p, q)<<'\n';	// 0

// 	q = new TreeNode(1);
// 	cout<<s.isSameTree(p, q)<<'\n'; // 1

// 	p->left = new TreeNode(1);
// 	q->right = new TreeNode(1);
// 	cout<<s.isSameTree(p, q)<<'\n';	// 0

// 	return 0;
// }
