/*
https://leetcode.com/problems/complete-binary-tree-inserter/description/
完全二叉树
同类题目 P919

参考思路
https://leetcode.com/problems/complete-binary-tree-inserter/discuss/178424/C%2B%2BJavaPython-O(1)-Insert/184173

Store tree nodes to a vector vecCBT in bfs order.
Node vecCBT[i] has left child vecCBT[2 * i + 1] and vecCBT[2 * i + 2]
下标从 0 开始，如果 parent 是 i，那么 left 就是 2*i+1, right 就是 2*i+2


So when insert the Nth node (0-indexed), we push it into the list.
we can find its parent vecCBT[(N - 1) / 2] directly.
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class CBTInserter{
public:
	vector<TreeNode *> vecCBT;
	CBTInserter(TreeNode* root) {
		vecCBT.push_back(root);
		// 充分利用 .size(), 动态添加，直到没有更多结点
		for( int i = 0; i < vecCBT.size(); i++ ){
			if( vecCBT[i]->left != NULL ){
				vecCBT.push_back(vecCBT[i]->left);
			}
			if( vecCBT[i]->right != NULL ){
				vecCBT.push_back(vecCBT[i]->right);
			}
		}
	}
	
	int insert(int v) {
		int size = vecCBT.size();
		TreeNode * node = new TreeNode(v);
		vecCBT.push_back(node);
		TreeNode * parent = vecCBT[(size-1) / 2];
		if( size % 2 == 1 ){
			parent->left = node;
		}else{
			parent->right = node;
		}
		return parent->val;
	}
	
	TreeNode* get_root() {
		return vecCBT[0];
	}
};

int main() {
	TreeNode * root = new TreeNode(1);
	CBTInserter * cbt = new CBTInserter(root);

	return 0;
}