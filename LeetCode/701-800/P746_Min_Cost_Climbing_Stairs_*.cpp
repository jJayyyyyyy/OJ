/*
https://leetcode.com/problems/min-cost-climbing-stairs/description/
第 i 级台阶需要给过路费 cost[i], 然后可以一次向上跨 1 或 2 级台阶
台阶编号 [0, n-1]
最终要到 top = n
求最少需要多少过路费
同类题目 P746

参考思路
https://leetcode.com/problems/min-cost-climbing-stairs/discuss/110111/Easy-to-understand-C++-using-DP-with-detailed-explanation
f[i] = cost[i] + min(f[i-1], f[i-2])
最后的 top = n 可以由 n-1 或 n-2 到达
*/

#include <iostream>
#include <string>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	int minCostClimbingStairs(vector<int> & cost) {
		// f[i] = cost[i] + min(f[i-1], f[i-2])
		int len = cost.size();
		vector<int> dp(len);
		dp[0] = cost[0];
		dp[1] = cost[1];
		for( int i = 2; i < len; i++ ){
			dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
		}
		// index of final top is len
		return min(dp[len-1], dp[len-2]);
	}
};
