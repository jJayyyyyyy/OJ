/*
https://leetcode.com/problems/distribute-coins-in-binary-tree/description/
给定一棵树, 每个结点的值表示该结点有多少个 coin
一共有 N 个结点, 一共有 N 个 coin, coin 只能在相邻结点之间移动
现在要把 coin 均分到每一个结点, 问需要移动多少次

同类题目 P979

参考思路
https://leetcode.com/problems/distribute-coins-in-binary-tree/solution/

首先确定某个结点需要多少的 coin 个数 need = node->val + left + right - 1;
也就是它可以从左右子树得到的数量 + 自身拥有的数量 - 1 (最后留下1个, 其他的发出去)
需要移动的数量是 abs(left) + abs(right)

这个过程从叶子开始
叶子如果没有 1 个 coin, 就要从其父结点借 coin
如果叶子的 coin 大于 1, 那么就把多的 coin 给父结点
*/

#include <iostream>
#include <vector>
#include <algoritm>
#include <cmath>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

struct TreeNode{
	int val;
	TreeNode * left, * right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	int ans;

	int dfs(TreeNode * root){
		if( root != NULL ){
			int left = dfs(root->left);
			int right = dfs(root->right);
			ans += abs(left) + abs(right);
			return root->val + left + right - 1;
		}else{
			return 0;
		}
	}

	int distributeCoins(TreeNode * root){
		ans = 0;
		dfs(root);
		return ans;
	}
};