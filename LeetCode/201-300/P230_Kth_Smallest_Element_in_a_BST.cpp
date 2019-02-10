/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
找出 BST 中第 k 小的结点值

同类题目
P230, P378

思路:
中序遍历, 得到升序数组 node_list[], 返回 node_list[k - 1]


Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

由于将所有元素都存储在了 node_list[], 且这是一个升序序列, 后续的插入删除可以直接在该数组上进行操作, 而查找第 k 小的元素也可以用下标直接得到, 空间换时间
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

class TreeNode
{
	int val;
	TreeNode * left, * right;
	TreeNode(int v)
	{
		val = v;
		left = right = NULL;
	}
};

class Solution
{
public:
	vector<int> node_list;

	void inOrder(TreeNode * root)
	{
		if( root != NULL )
		{
			inOrder(root->left);
			node_list.push_back(root->val);
			inOrder(root->right);
		}
	}

	int kthSmallest(TreeNode* root, int k) {
		inOrder(root);
		return node_list[k - 1];
	}
};

/*
// 
class Solution
{
public:
	int cnt;
	int ans;
	void inOrder(TreeNode * root, const int k)
	{
		if( root != NULL )
		{
			inOrder(root->left, k);
			cnt++;
			if( k == cnt )
			{
				ans = root->val;
			}
			inOrder(root->right, k);
		}
	}

	int kthSmallest(TreeNode* root, int k) {
		cnt = 0;
		inOrder(root, k);
		return ans;
	}
};
*/