/*
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
判断 BST 中是否存在这样的两个结点，它们的值的和等于 k
同类题目 P653

先按中序遍历 BST，得到递增数组
然后判断前两个元素之和是否超过了k，或者最后两个元素之和小于k
最后就是一个二重循环，逐个判断是否存在v1 + v2 == k

1. 除了能加快速度，貌似和BST没啥关系
2. 把数据放到数组里面，比递归调用函数的开销要小，不过最大的开销还是 I/O 
*/

#include <iostream>
#include <vector>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution{
public:
	vector<int> valList;

	void inOrder(TreeNode * root){
		if( root != NULL ){
			inOrder(root->left);
			valList.push_back(root->val);
			inOrder(root->right);
		}
	}

	bool findTarget(TreeNode* root, int k) {
		inOrder(root);
		int len = valList.size();

		if( len < 2 ){
			return false;
		}else{
			if( valList[0] + valList[1] > k || valList[len-2] + valList[len-1] < k ){
				return false;
			}else{
				bool ans = true;
				for( int i = 0; i < len - 1; i++ ){
					for( int j = i + 1; j < len; j++ ){
						if( valList[i] + valList[j] == k ){
							return true;
						}
					}
				}
				return false;
			}
		}
	}
};