/*
https://leetcode.com/problems/house-robber-iii/description/

同类题目 P337, P198, P213

参考思路
https://leetcode.com/problems/house-robber-iii/discuss/79333/Simple-C++-solution
与之前的 house robber 一样, 我们不能抢相邻的房子
本题的邻里关系是树形结构, 因此如果抢了根结点 root, 就不能抢左右孩子 root->left, root->right

为此, 我们的基本思路是, 要么抢 sum1 = [根结点 root + 孙子一层结点 grandchildren], 要么抢 sum2 = [左孩子 left + 右孩子 right]
求出 max(sum1, sum2) 即可

注意不能用层序遍历的思想, 这样会错过测试样例 c

部分测试样例
a. [4,1,null,2,null,3] --- 7

b. [3,4,5,1,3,null,1] --- 9

c. [2,1,3,null,4] --- 7
*/

#include <iostream>
using namespace std;

const static auto c = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution
{
public:
	int rob(TreeNode * root)
	{
		int left = 0, right = 0;
		return rob_house(root, left, right);
	}
	
	int rob_house(TreeNode * root, int & left, int & right)
	{
		if( root == NULL )
		{
			return 0;
		}

		int left_left = 0, left_right = 0;
		int right_left = 0, right_right = 0;
		left = rob_house(root->left, left_left, left_right);
		right = rob_house(root->right, right_left, right_right);

		int sum_of_root_and_grandchildren = root->val + left_left + left_right + right_left + right_right;
		int sum_of_children = left + right;
		return max(sum_of_root_and_grandchildren, sum_of_children);
	}
};


