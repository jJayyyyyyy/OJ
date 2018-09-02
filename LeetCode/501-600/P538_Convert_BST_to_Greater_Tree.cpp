/*
https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
分段逆转字符串
同类题目 P538

思路1
先中序遍历树，得到升序序列
再遍历树, 二分查找, 加上大值

缺点: 2次遍历, n次 lg(n) 的查找，耗时过多 (190ms+)


思路2
RDL, 右->中->左, 降序遍历BST
sum保存了所有大于 A->val 的结点的值
(~24ms)

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	vector<int> in;
	
	void inTrav(TreeNode * root){
		if( root != NULL ){
			inTrav(root->left);
			in.push_back(root->val);
			inTrav(root->right);
			
		}
	}
	
	void plusTrav(TreeNode * root){
		if( root != NULL ){
			vector<int>::iterator up = upper_bound(in.begin(), in.end(), root->val);
			for( ; up != in.end(); up++ ){
				root->val += *up;
			}
			plusTrav(root->left);
			plusTrav(root->right);
		}
	}
	
	// 先中序遍历树，得到升序序列
	// 再遍历树, 二分查找, 加上大值
	TreeNode * convertBST(TreeNode * & root){
		if( root == NULL ){
			return NULL;
		}
		
		inTrav(root);
		plusTrav(root);
		return root;
	}
};

class Solution2{
public:
	int sum = 0;

	// RDL, 右->中->左, 降序遍历BST
	void inTrav(TreeNode * & root){
		if( root != NULL ){
			inTrav(root->right);
			sum += root->val;
			root->val = sum;
			inTrav(root->left);
		}
	}

	TreeNode * convertBST(TreeNode * & root){
		if( root == NULL ){
			return NULL;
		}
		
		inTrav(root);
		return root;
	}
};


int main(){
	Solution s;
	
	TreeNode * root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(13);
	
	s.convertBST(root);
	return 0;
}
