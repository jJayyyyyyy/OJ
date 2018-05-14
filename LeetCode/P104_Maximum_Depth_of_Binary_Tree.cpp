/*
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 * 求一棵树的深度
 * 同类题目 P104, P107
 * 在PAT上做这类题目时, 可以自定义数据结构, 所以以前总是在 struct 里面增加一个 level 属性, 然后层序遍历, 子.level = 父.level +1, 再遍历一遍即可得到结果
 * 本题的树, 数据结构已经给定, 不能改变, 因此需要对原方法进行微调
 * 思路: 仍然进行层序遍历, 增加一个 depth 变量记录当前层数, 然后把该层的 node 全部 pop, 再进入下一层
 * 在对该层进行 pop 时, 需要先记录此时此刻的  sizeOfThisLayer = q.size()
*/

// #include <iostream>
// #include <queue>
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
	int maxDepth(TreeNode *root) {
		if( root == NULL ){
			return 0;
		}

		queue<TreeNode *> q;
		q.push(root);
		int depth = 0;
		while( q.size() ){
			depth++;
			int sizeOfThisLayer = q.size();
			for( int i = 0; i < sizeOfThisLayer; i++ ){
				TreeNode * node = q.front();
				// vis(node);
				q.pop();

				if( node->left != NULL ){
					q.push(node->left);
				}
				if( node->right != NULL ){
					q.push(node->right);
				}
			}
		}
		return depth;
	}
	
	
	// 递归法
	// 参考: https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/34207/My-code-of-C++-Depth-first-search-and-Breadth-first-search
	
	// int maxDepth2(TreeNode *root){
	// 	return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
	// }
};



// int main(){
// 	Solution s;

// 	TreeNode * p = NULL;
// 	cout<<s.maxDepth(p)<<'\n';	// 0

// 	p = new TreeNode(3);
// 	cout<<s.maxDepth(p)<<'\n';	// 1

// 	p->left = new TreeNode(9);
// 	cout<<s.maxDepth(p)<<'\n';	// 2

// 	p->right = new TreeNode(20);
// 	cout<<s.maxDepth(p)<<'\n';	// 2

// 	p->right->left = new TreeNode(15);
// 	cout<<s.maxDepth(p)<<'\n';	// 3

// 	p->right->right = new TreeNode(7);
// 	cout<<s.maxDepth(p)<<'\n';	// 3
// 	return 0;
// }
