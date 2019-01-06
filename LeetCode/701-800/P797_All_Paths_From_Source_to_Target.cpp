/*
https://leetcode.com/problems/all-paths-from-source-to-target/description/
有向图, 找出从 src 到 dest 的所有路径
同类题目 P797

dfs即可
*/
#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	vector< vector<int> > g, ans;
	vector<int> tmpPath;

	void dfs(int now, int dest){
		if( now == dest ){
			tmpPath.push_back(now);
			ans.push_back(tmpPath);
			tmpPath.pop_back();
		}else{
			tmpPath.push_back(now);
			for( int next : g[now] ){
				dfs(next);
			}
			tmpPath.pop_back();
		}
	}

	vector<vector<int>> allPathsSourceTarget(vector< vector<int> > & graph) {
		int src = 0;
		int dest = graph.size() - 1;
		g = graph;
		dfs(src, dest);
		return ans;
	}
};