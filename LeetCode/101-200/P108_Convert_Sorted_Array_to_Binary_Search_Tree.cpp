/*
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 * 给定一个升序序列, 要造一棵二叉平衡搜索树
 * 同类题目 P108
 * 
 * 思路1: 构造二叉完全排序树, 完全二叉树一定是平衡树
 * 思路2: Discuss中的votes最多的解法, 但是目前还没有想明白那种解法造的树是平衡树
 * 思路3: 构造AVL的通用解法, 但是给定的数据结构 TreeNode 没有 height, 所以...
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


// Solution1
class Solution {
public:
	vector<int> a;
	int x;

	// BST 中序是递增的
	TreeNode * inOrder(int i, int n){
		if( i <= n ){
			TreeNode * left = inOrder(i * 2, n);
			TreeNode * root = new TreeNode(a[x++]);
			TreeNode * right = inOrder(i * 2 + 1, n);
			root->left = left;
			root->right = right;
			return root;
		}else{
			return NULL;
		}
	}

	TreeNode* sortedArrayToBST(vector<int>& nums){
		int n = nums.size();
		a = nums;
		a.insert(a.begin(), -0x3fff0000);
		x = 1;
		TreeNode * root = inOrder(1, n);
		return root;
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;
// 	vector<int> nums;

// 	TreeNode * root = s.sortedArrayToBST(nums);

// 	nums.push_back(-10);
// 	nums.push_back(-3);
// 	nums.push_back(0);
// 	nums.push_back(5);
// 	nums.push_back(9);

// 	root = s.sortedArrayToBST(nums);

// 	return 0;
// }
