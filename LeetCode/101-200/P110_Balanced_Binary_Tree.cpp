/*
 * https://leetcode.com/problems/balanced-binary-tree/description/
 * 判断一棵树是否为平衡树
 * 同类题目 P110, P108, P111
 * 
 * 思路: 
 * 参考: https://leetcode.com/problems/balanced-binary-tree/discuss/35691/The-bottom-up-O(N)-solution-would-be-better
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
			if( lH == -1 ){
				return -1;
			}

			int rH = getHeight(root->right);
			if( rH == -1 ){
				return -1;
			}

			if( abs(lH - rH) > 1 ){
				return -1;
			}

			return max( lH, rH ) + 1;
		}
	}

	bool isBalanced(TreeNode * root) {
		return getHeight(root) != -1;
	}
};


