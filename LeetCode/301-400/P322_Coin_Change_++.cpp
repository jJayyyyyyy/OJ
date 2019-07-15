/*
https://leetcode.com/problems/coin-change/description/?goto=old
给一堆硬币 coins，判断组成总数为 amount 的组合，最少需要多少硬币
同类题目 P332

思路:
动态规划

首先明确没有五毛钱，最小面额是 1元，面额都是整数
所以 最大 数量 就是 amount
如果最终数量超过 amount，说明无解

然后，如果有解 f[amount] = f[amount - valuei] + 1
*/

#include <iostream>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		// 首先明确没有五毛钱，最小面额是 1元，面额都是整数
		// 所以 最大 数量 就是 amount
		// 如果最终数量超过 amount，说明无解
		int maxAmount = amount + 1;
		vector<int> dp(maxAmount, maxAmount);
		dp[0] = 0;
		for( int ix = 1; ix <= amount; ix++ ){
			for( int value : coins ){
				if( ix >= value ){
					dp[ix] = min(dp[ix], dp[ix - value] + 1);
				}
			}
		}

		if( dp[amount] > amount ) {
			return -1;
		}
		else{
			return dp[amount];
		}
	}
};