/*
https://leetcode.com/problems/combinations/description/
n 个数中选 k 个, 一共有 C(k,n) 种组合, 求出所有组合
同类题目 P077

思路类似于 PAT 求所有最短路径中的 DFS
在 dfs 中进行循环
好久没练 PAT, 基本功都忘的差不多了 T_T, 这个递归写了半天...
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector< vector<int> > ans;
	vector<int> line;
	int up;

	void dfs(int cur, int k){
		if( line.size() == k ){
			ans.push_back(line);
			return;
		}

		for( int i = cur; i <= up; i++ ){
			// 稍加剪枝, 总体时间差不多
			// if( line.size() && line[0] > up - k + 1 ){
			// 	break;
			// }

			line.push_back(i);
			dfs(i+1, k);
			line.pop_back();
		}
	}

	vector<vector<int> > combine(int n, int k){
		// 若 k > n, 则没有这样的组合, 直接退出
		if( n < k ){
			return ans;
		}
		
		int cur = 1;
		up = n;
		dfs(cur, k);
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Solution s;
	s.combine(4, 2);

	return 0;
}
