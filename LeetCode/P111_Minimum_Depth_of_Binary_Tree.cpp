/*
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * 求一个树的最小深度
 * 同类题目 P111, P112, (P110)
 * 
 * 思路: 用与P110类似的方法, 求出深度/高度, max 换成 min
 * 注意 if-else 的逻辑, 如果不是叶子结点, 则要往下继续追溯
 * 注意 case2 的答案是 2
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

// 结点结构
// struct TreeNode{
// 	int val;
// 	TreeNode *left, *right;
// 	TreeNode(int x)	: val(x), left(NULL), right(NULL) {}
// };


// Solution
class Solution {
public:
	int getHeight(TreeNode * root){
		if( root == NULL ){
			return 0;
		}else{
			int lH = getHeight(root->left);
			int rH = getHeight(root->right);

			// root->left == NULL && root->right == NULL
			// 判断是否为叶子结点
			if( lH == 0 && rH == 0 ){
				return 1;
			}
			
			// root->left != NULL && root->right == NULL
			else if( lH > 0 && rH == 0 ){
				return lH + 1;
			}
			
			// root->left == NULL && root->right != NULL
			else if( lH == 0 && rH > 0 ){
				return rH + 1;
			}
			
			// root->left != NULL && root->right != NULL
			else{
				return min( lH, rH ) + 1;
			}
		}
	}

	int minDepth(TreeNode * root) {
		return getHeight(root);
	}
};


// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;


// 	TreeNode * root = NULL;
// 	cout<<s.minDepth(root)<<'\n';	// 0

// 	root = new TreeNode(1);
// 	cout<<s.minDepth(root)<<'\n';	// 1

// 	root->left = new TreeNode(2);
// 	cout<<s.minDepth(root)<<'\n';	// 2, case 2

// 	root->right = new TreeNode(20);
// 	cout<<s.minDepth(root)<<'\n';	// 2

// 	root->right->left = new TreeNode(15);
// 	cout<<s.minDepth(root)<<'\n';	// 2

// 	root->right->right = new TreeNode(7);
// 	cout<<s.minDepth(root)<<'\n';	// 2

// 	return 0;
// }