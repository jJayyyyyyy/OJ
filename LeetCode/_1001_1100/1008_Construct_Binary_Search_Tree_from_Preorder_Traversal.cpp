/*
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
给定 BST 的前序, 造出这棵 BST
同类题目 P1008

参考思路
https://github.com/jJayyyyyyy/OJ/blob/master/notes/Question3.md
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	vector<int> in, pre;
	unordered_map<int, int> val_to_index;

	TreeNode * in_pre(int inL, int inR, int preL, int preR)
	{
		if( preL > preR )
		{
			return NULL;
		}

		int valroot = pre[preL];
		TreeNode * root = new TreeNode(valroot);
		int iroot = val_to_index[valroot];
		int numLeft = iroot - inL;
		root->left  = in_pre(inL, iroot - 1, preL + 1, preL + numLeft);
		root->right = in_pre(iroot + 1, inR, preL + numLeft + 1, preR);
		return root;
	}

	TreeNode* bstFromPreorder(vector<int>& preorder) {
		int size = preorder.size();
		if( size == 0 )
		{
			return NULL;
		}
		else
		{
			pre = preorder;
			in = preorder;
			sort(in.begin(), in.end());
			for( int i = 0; i < size; i++ )
			{
				int val = in[i];
				val_to_index[val] = i;
			}
			TreeNode * root = in_pre(0, size - 1, 0, size - 1);
			return root;
		}
	}
};