/*
https://leetcode.com/problems/subtree-of-another-tree/description/
给定两棵树s, t，判断 t 是否为 s 的子树
同类题目 P572, P100

参考思路
https://leetcode.com/problems/subtree-of-another-tree/discuss/102734/19ms-C++-solution-beats-99.9
不直接从根节点开始判断，而是先找到s中所有与t高度相同的结点 possibleRootList
然后用 P100 的方法依次判断 root 与 t 是否表示了同一棵树
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
	TreeNode *left, *right;
	int val;
	TreeNode(int v){
		val = v;
		left = right = NULL;
	}
};
class Solution{
private:
	vector<TreeNode *> possibleRootList;

	bool isSame(TreeNode * subs, TreeNode * t){
		if( subs == NULL && t == NULL ){
			return true;
		}else if( subs != NULL && t == NULL ){
			return false;
		}else if( subs == NULL && t != NULL ){
			return false;
		}else{
			return ( subs->val == t->val ) && isSame(subs->left, t->left) && isSame(subs->right, t->right);
		}
	}

	int getHeight(TreeNode * root){
		if( root == NULL ){
			return 0;
		}

		int lH = getHeight(root->left);
		int rH = getHeight(root->right);
		int rootH = max(lH, rH) + 1;
		return rootH;
	}

	int getHeight(TreeNode * root, int targetH){
		if( root == NULL ){
			return 0;
		}

		int lH = getHeight(root->left, targetH);
		int rH = getHeight(root->right, targetH);
		int rootH = max(lH, rH) + 1;
		if( rootH == targetH ){
			possibleRootList.push_back(root);
		}
		return rootH;
	}

public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if( s == NULL && t == NULL ){
			return true;
		}else if( s != NULL && t == NULL ){
			return false;
		}else if( s == NULL && t != NULL ){
			return false;
		}else{
			int tH = getHeight(t);
			int sH = getHeight(s, tH);

			for( TreeNode * root : possibleRootList ){
				if( isSame(root, t) ){
					return true;
				}
			}
			return false;
		}
	}
};