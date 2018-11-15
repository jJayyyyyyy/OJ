/*
https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
给定一棵二叉树，计算每一层结点值的平均值
同类题目 P637

*/

#include <iostream>
#include <vector>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int v){
		val = v;
		left = right = NULL;
	}
};

class Solution{
public:
	vector<double> averageOfLevels(TreeNode * root) {
		// level order trav
		vector<double> ans;
		queue<TreeNode *> q;
		q.push(root);

		while( q.size() ){
			int len = q.size();
			long long sum = 0;
			for( int i = 0; i < len; i++){
				TreeNode * parent = q.front();
				q.pop();
				sum += parent->val;
				if( parent->left != NULL ){
					q.push(parent->left);
				}
				if( parent->right != NULL ){
					q.push(parent->right);
				}
			}
			ans.push_back((double) sum / len);
		}
		return ans;
	}
};
