/*
https://leetcode.com/problems/flower-planting-with-no-adjacent/description/?goto=old
有 N 个花园 (编号 1 ~ N )，每个花园最多有三条通往其他花园的路 (无向图)
你有 4 种花，要把它们种在 N 个花园里，每个花园一种类型
要求相邻花园的花的类型不一样
输出一种可能的种法
同类题目 P1042

参考思路
https://leetcode.com/problems/flower-planting-with-no-adjacent/discuss/290858/JavaC++Python-Greedily-Paint

https://leetcode.com/problems/flower-planting-with-no-adjacent/discuss/290923/C++-Greedy

贪心算法，题目保证了有解，而且有 4 种花可以种，通路最多有 3 条
说明不管种花的顺序如何，每个花园肯定有一种可种的花

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
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector< vector<int> > graph(N);
		// 先构建无向图
		for (vector<int> & path : paths) {
			int garden1 = path[0] - 1;
			int garden2 = path[1] - 1;
			graph[garden1].push_back(garden2);
			graph[garden2].push_back(garden1);
		}

		vector<int> ans(N);
		for (int garden = 0; garden < N; garden++) {
			bool neighbor[5] = {false};
			// 先记录邻居的花
			for (int garden : graph[garden]) {
				int flower = ans[garden];
				neighbor[flower] = true;
			}
			// 然后从邻居没有的花里面随便选一种拿来种就可以了
			for (int flower = 1; flower <= 4; flower++) {
				if (neighbor[flower] == false) {
					ans[garden] = flower;
					break;
				}
			}
		}
		return ans;
	}
};