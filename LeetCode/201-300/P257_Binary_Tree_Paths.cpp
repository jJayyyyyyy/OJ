/*
https://leetcode.com/problems/binary-tree-paths/description/
找出每一条 根->叶 的路径 (遍历顺序为NLR前序)
同类题目 P257

string s = to_string(123);
http://www.cplusplus.com/reference/string/to_string/?kw=to_string
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	vector<string> ans;
	vector<int> path;

	void addAns(){
		if( path.size() > 0 ){
			string onePath = to_string(path[0]);
			for( int i = 1; i < path.size(); i++ ){
				onePath += "->" + to_string(path[i]);
			}
			ans.push_back( onePath );
		}
	}

	void preTravTree(TreeNode * p){
		if( p != NULL ){
			path.push_back(p->val);

			if( p->left == NULL && p->right == NULL ){
				addAns();
			}else{
				preTravTree(p->left);
				preTravTree(p->right);
			}

			path.pop_back();
		}
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		/* begin test */
		ans.clear();
		path.clear();
		/* end test */

		preTravTree(root);
		return ans;
	}
};

int main(){
	Solution s;

	TreeNode *root = NULL;
	s.binaryTreePaths(root);

	root = new TreeNode(1);
	s.binaryTreePaths(root);

	root->left = new TreeNode(2);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);
	s.binaryTreePaths(root);

	return 0;
}
