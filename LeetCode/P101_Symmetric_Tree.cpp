/*
 * https://leetcode.com/problems/symmetric-tree/description/
 * 判断一棵树是否以根对称
 * 同类题目 P100, P101
 * 注意, 本题的树, 仅仅以根为轴对称, 而不是每个子结点都对称, 审题要仔细
 * 思路是添加一个辅助函数, 然后把1棵树root, 复制(引用)成2棵树p, q
 * 判断轴对称 cmp(p->left, q->right) && cmp(p->right, q->left)
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
	bool isSymmetric(TreeNode* root){
		if( root == NULL ){
			return true;
		}else{
			return cmp(root->left, root->right);
		}
	}
	bool cmp(TreeNode * p, TreeNode * q) {
		if( p == NULL && q == NULL ){
			return true;
		}else if( p == NULL || q == NULL ){
			return false;
		}else{
			if( p->val == q->val ){
				return cmp(p->left, q->right) && cmp(p->right, q->left);
			}else{
				return false;
			}
		}
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;

// 	TreeNode *p = NULL;//, *q = NULL;
// 	cout<<s.isSymmetric(p)<<'\n';	// 1

// 	p = new TreeNode(1);
// 	cout<<s.isSymmetric(p)<<'\n';	// 1

// 	p->left = new TreeNode(2);
// 	cout<<s.isSymmetric(p)<<'\n';	// 0


// 	p->right = new TreeNode(2);
// 	cout<<s.isSymmetric(p)<<'\n';	// 1

// 	p->left->left = new TreeNode(3);
// 	p->left->right = new TreeNode(4);
// 	p->right->left = new TreeNode(4);
// 	p->right->right = new TreeNode(3);
// 	cout<<s.isSymmetric(p)<<'\n';	// 1

// 	return 0;
// }
