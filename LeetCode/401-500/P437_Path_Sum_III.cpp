/*
https://leetcode.com/problems/path-sum-iii/description/
遍历树，寻找连续的，自上而下的路径(不一定从根结点开始，但是需要连续的一段向下的路径)，使得结点的和等于给定值
同类题目 P437, 

参考: https://leetcode.com/problems/path-sum-iii/discuss/154952/Beat-99.85-with-C++

思路:
1. 前序遍历, 保存结点路径
2. 从当前结点开始，向上计算结点值之和
3. 

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


struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution{
public:
	vector<TreeNode *> path;
	int ansCnt;
	int expSum;

	void preTrav( TreeNode * root ){
		if( root != NULL ){
			path.push_back(root);
			int tmpSum = 0;
			for( int i = path.size() - 1; i >= 0; i-- ){
				tmpSum += path[i]->val;
				if( tmpSum == expSum ){
					ansCnt++;
				}
			}
			preTrav(root->left);
			preTrav(root->right);
			path.pop_back();
		}
	}

	int pathSum(TreeNode* root, int sum) {
		ansCnt = 0;
		expSum = sum;
		preTrav(root);
		return ansCnt;
	}
};
