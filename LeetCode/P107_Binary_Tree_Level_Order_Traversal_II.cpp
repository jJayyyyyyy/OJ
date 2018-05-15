/*
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 * 求一棵树的深度
 * 同类题目 P104, P107
 * 层序遍历方法参见 P104
 * 思路: 使用 vector<int> 和 stack<vector<int> >, 先存储该层的序列, 再把 vector 压入 stack , 最后把 stack 输出到 新的 vector<vector<int> >
*/

// #include <iostream>
// #include <queue>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

// struct TreeNode{
// 	int val;
// 	TreeNode *left, *right;
// 	TreeNode(int x)	: val(x), left(NULL), right(NULL) {}
// };


class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > ans;

		if( root != NULL ){
			queue<TreeNode *> q;
			q.push(root);

			stack<vector<int> > st;

			while( q.size() ){
				// ans.push_back()
				int n = q.size();
				vector<int> level;
				for( int i = 0; i < n; i++ ){
					TreeNode * node = q.front();
					// vis(node)
					level.push_back(node->val);
					q.pop();

					if( node->left != NULL ){
						q.push(node->left);
					}
					if( node->right != NULL ){
						q.push(node->right);
					}
				}
				
				st.push(level);
			}

			while( st.size() ){
				ans.push_back( st.top() );
				st.pop();
			}
		}
		return ans;
	}
};

// int main(){
// 	Solution s;

// 	TreeNode * p = NULL;

// 	p = new TreeNode(3);

// 	p->left = new TreeNode(9);

// 	p->right = new TreeNode(20);

// 	p->right->left = new TreeNode(15);

// 	p->right->right = new TreeNode(7);

// 	vector<vector<int> > ans = s.levelOrderBottom(p);

// 	for(int i = 0; i < ans.size(); i++ ){
// 		for( int j = 0; j < ans[i].size(); j++ ){
// 			cout<<ans[i][j]<<' ';
// 		}
// 		cout<<'\n';
// 	}

// 	// 15 7
// 	// 9 20
// 	// 3
// 	return 0;
// }