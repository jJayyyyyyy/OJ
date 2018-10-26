/*
https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
给定一棵BST, 返回最小的结点值之差(绝对值最小)

同类题目 P783, P530(结点值非负)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> valList;

	void inTrav(TreeNode * root){
		if( root ){
			inTrav(root->left);
			valList.push_back(root->val);
			inTrav(root->right);
		}
	}

	int minDiffInBST(TreeNode * root) {
		inTrav(root);
		int mindiff = -1;
		int len = valList.size();
		if( len >= 2 ){
			mindiff = valList[1] - valList[0];
			for( int i = 2; i < len; i++ ){
				int diff = valList[i] - valList[i-1];
				if( diff < mindiff ){
					mindiff = diff;
				}
			}
		}
		return mindiff;
	}
};
