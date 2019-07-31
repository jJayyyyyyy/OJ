/*
https://leetcode.com/problems/combination-sum/description/?goto=old

同类题目 P039

参考思路
https://leetcode.com/problems/combination-sum/discuss/16502/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)

其实就是 PAT 里面常出现的DFS的套路

void dfs(...){
	for(...){
		tmp.push_back(...);
		dfs(...);
		tmp.pop_back();
	}
}

参考思路里面的通用解法值得学习

*/

#include <vector>
using namespace std;

class Solution {
public:
	vector< vector<int> > ans;
	int len;
	vector<int> tmp;

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		len = candidates.size();
		if (len > 0 && target > 0) {
			int start = 0;
			dfs(target, start, candidates);
		}
		return ans;
	}

	void dfs(int target, int start, vector<int> & candidates) {
		if (target > 0) {
			for ( int i = start; i < len; i++) {
				int num = candidates[i];
				tmp.push_back(num);
				dfs(target - num, i, candidates);
				tmp.pop_back();
			}
		}
		else if (target == 0) {
			ans.push_back(tmp);
		}
		else{
			return;
		}
	}
};