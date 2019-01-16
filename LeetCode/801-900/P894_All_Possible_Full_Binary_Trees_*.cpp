/*
https://leetcode.com/problems/all-possible-full-binary-trees/description/

同类题目 P894

Solution
https://leetcode.com/problems/all-possible-full-binary-trees/solution/
https://leetcode.com/problems/all-possible-full-binary-trees/discuss/164134/C++-solution-easy-to-understand-and-use-chinese:)
*/


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

static int ioSpeedUp=[](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
	unordered_map<int, vector<TreeNode *> > m;

	vector<TreeNode*> FBT(int x){
		if( m.find(x) == m.end() ){
			vector<TreeNode *> ans;
			if( x == 1 ){
				TreeNode * root = new TreeNode(0);
				ans.push_back(root);
			}else if( x % 2 == 1 ){
				for( int i = 0; i < x; i++ ){
					int j = x - 1 - i;
					vector<TreeNode *> subleft = FBT(i);
					vector<TreeNode *> subright = FBT(j);
					for( TreeNode * left : subleft ){
						for( TreeNode * right : subright ){
							TreeNode * root = new TreeNode(0);
							root->left = left;
							root->right = right;
							ans.push_back(root);
						}
					}
				}
			}
			m[x] = ans;
		}
		return m[x];
	}

	vector<TreeNode*> allPossibleFBT(int N){
		return FBT(N);
	}
};