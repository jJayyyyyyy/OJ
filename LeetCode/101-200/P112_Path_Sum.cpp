/*
 * https://leetcode.com/problems/path-sum/description/
 * 对于每一条从树根到叶子的路径, 对结点值求和, 判断是否存在这样一条路径, 其权值之和等于给定值
 * 同类题目 P112, P111
 * 
 * 注意 if 的逻辑, 判断 subsum == ans 的前提是: 该结点必须是叶子结点, 参见 case 2, 输入是 root = [1, 2], sum = 1
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

// 结点结构
// struct TreeNode{
// 	int val;
// 	TreeNode *left, *right;
// 	TreeNode(int x)	: val(x), left(NULL), right(NULL) {}
// };


// Solution
class Solution {
public:
	bool hasPath;
	int ans, subsum;

	void dfs(TreeNode * root){
		if( root != NULL ){
			subsum += root->val;
			dfs(root->left);
			dfs(root->right);
			
			// 判断是否为叶子结点
			if( root->left == NULL && root->right == NULL ){
				if( subsum == ans ){
					hasPath = true;
				}
			}
			
			subsum -= root->val;
		}
	}

	bool hasPathSum(TreeNode * root, int sum) {
		if( root == NULL ){
			return false;
		}

		hasPath = false;
		subsum = 0;
		ans = sum;
		dfs(root);
		return hasPath;
	}
};

// Solution2, 类似最短路径的做法, 还可以记录路径
class Solution2 {
public:
	bool hasPath, ansPath;
	int ans;
	vector<int> nodeList;

	void dfs(TreeNode * root){
		if( root != NULL ){
			nodeList.push_back(root->val);
			dfs(root->left);
			dfs(root->right);
			// 判断是否为叶子结点
			if( root->left == NULL && root->right == NULL ){
				calc();
			}
			nodeList.pop_back();
		}
	}

	void calc(){
		int subsum = 0;
		for( auto v : nodeList ){
			subsum += v;
		}
		if( subsum == ans ){
			hasPath = true;
			ansPath = nodeList;
		}
	}

	bool hasPathSum(TreeNode * root, int sum) {
		if( root == NULL ){
			return false;
		}

		hasPath = false;
		subsum = 0;
		ans = sum;
		dfs(root);
		return hasPath;
	}
};



// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;

// 	TreeNode * r1 = NULL;
// 	cout<<s.hasPathSum(r1, 0)<<'\n';	// false
// 	TreeNode * r2 = new TreeNode(1);
// 	r2->left = new TreeNode(2);
// 	cout<<s.hasPathSum(r2, 1)<<'\n';	// false
// 	cout<<s.hasPathSum(r2, 2)<<'\n';	// false
// 	cout<<s.hasPathSum(r2, 3)<<"\n\n\n";	// true



// 	TreeNode * root = NULL;
// 	cout<<s.hasPathSum(root, 22)<<'\n';	// false

// 	root = new TreeNode(5);
// 	cout<<s.hasPathSum(root, 22)<<'\n';	// false

// 	root->left = new TreeNode(4);
// 	root->left->left = new TreeNode(11);
// 	root->left->left->left = new TreeNode(7);
// 	root->left->left->right = new TreeNode(2);
// 	cout<<s.hasPathSum(root, 22)<<'\n';	// true

// 	root->right = new TreeNode(8);
// 	root->right->left = new TreeNode(13);
// 	root->right->left->right = new TreeNode(4);
// 	root->right->left->right->right = new TreeNode(1);

// 	cout<<s.hasPathSum(root, 22)<<'\n';	// true

// 	return 0;
// }