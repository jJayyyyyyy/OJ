/*
https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
对 N叉树 进行层序遍历
同类题目 P429, 

[PAT_A_1127_ZigZagging_on_a_Tree](https://github.com/jJayyyyyyy/OJ/tree/master/PAT/advanced_level/1127_ZigZagging_on_a_Tree)

在 PAT_A_1127_ZigZagging_on_a_Tree, 我们可以自定义结点结构, 即可以加上 层高level 这么一个属性

而本题的结点结构已经给定，所以我们要对算法做些修改

总体思路肯定是用 queue 进行 BFS
首先这样考虑，假设已经处理完了某一层，当我们要对下一层做处理之前，这一层的结点一定要全部pop掉，也就是queue要变成空的
但是，我们不一定要连续把这一层排空。换一种思路，我们只需要记下当前这一层有几个结点，也就是 levelCnt=q.size(), 这样只需要做 levelCnt 次 q.pop()，就可以把当前这一层的结点排空了。

参考 https://leetcode.com/problems/n-ary-tree-level-order-traversal/discuss/151149/C++-O(N)-BFS

*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Node{
public:
	int val = NULL;
	vector<Node *> children;

	Node(){}

	Node(int _val, vector<Node *> _children){
		val = _val;
		children = _children;
	}
};

class Solution{
public:
	vector<vector<int> > levelOrder(Node * root){
		vector<vector<int> > ans;

		if( root != NULL ){
			queue<Node *> q;
			q.push(root);
			
			while( q.size() ){
				vector<int> level;

				int levelCnt = q.size();
				for( int i = 0; i < levelCnt; i++ ){
					level.push_back( q.front()->val );
					for( auto child : q.front()->children ){
						q.push(child);
					}
					q.pop();
				}
				ans.push_back(level);
			}
		}
		return ans;
	}
};
