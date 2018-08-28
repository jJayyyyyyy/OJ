/*
https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
给定一棵 BST, 求出现次数最多的值
同类题目 P501


思路1:
中序遍历，得到升序序列
求出现次数最多的值
时间 O(n)
空间 O(n)


TODO:
思路2:
中序遍历(升序)
把出现次数最多的元素压栈
空间 O(1)

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	unordered_map<int, int> m;

	void inTrav( TreeNode * root ){
		if( root != NULL ){
			inTrav(root->left);
			int key = root->val;
			if( m.find(key) == m.end() ){
				m[key] = 1;
			}else{
				m[key]++;
			}
			inseq.push_back(root->val);
			inTrav(root->right);
		}
	}

	vector<int> findMode(TreeNode * root) {
		vector<int> ans;

		if( root != NULL ){
			inTrav(root);
			int maxcnt = 0;
			for( auto it = m.begin(); it != m.end(); it++ ){
				if( it->second > maxcnt ){
					maxcnt = it->second;
				}
			}

			for( auto it = m.begin(); it != m.end(); it++ ){
				if( it->second == maxcnt ){
					ans.push_back(it->first);
				}
			}
		}

		return ans;
	}
};

