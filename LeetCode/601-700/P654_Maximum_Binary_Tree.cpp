/*
https://leetcode.com/problems/maximum-binary-tree/description/
输入一个数组，用数组中的最大值作为根结点，并将数组分为两个子数组，递归地进行这一过程，构造最大树
类似于 中序+前序/后序 造树
同类题目 P654
*/

#include <iostream>
#include <vector>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// 思路类似选择排序, 时间复杂度 O(n^2)
class Solution{
public:
	TreeNode * constructMaximumBinaryTree(vector<int> & nums){
		return makeTree(nums, 0, nums.size()-1);
	}

	TreeNode * makeTree( vector<int> & nums, int left, int right ){
		if( left > right ){
			return NULL;
		}

		// 遍历数组找出最大值
		// 不是在 [0, len-1] 找最大值
		// 而是在 [left, right] 找最大值
		int maxIdx = left;
		int maxVal = nums[maxIdx];
		for( int i = left; i <= right; i++ ){
			// 使用临时变量 tmpVal 减少一次访存
			int tmpVal = nums[i];
			if( tmpVal > maxVal ){
				maxVal = tmpVal;
				maxIdx = i;
			}
		}

		// right = len-1
		// [left, maxIdx-1], [maxIdx], [maxIdx+1, right];
		TreeNode * root = new TreeNode(maxVal);
		root->left = makeTree(nums, left, maxIdx-1);
		root->right = makeTree(nums, maxIdx+1, right);
		return root;
	}
};

int main(){
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(6);
	v.push_back(0);
	v.push_back(5);
	Solution s;
	TreeNode * root = s.constructMaximumBinaryTree(v);
	return 0;
}
