/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 * 给出股票走势, 可以多次买入卖出, 使总利润最大化
 * 同类题目 P121, P122
 * 
 * 参考: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/
 * Approach #2 + Approach #3
 *
 * 思路: 题目要求的最大利润, 就是找出所有的【连续的valley到peak】, ( 每一段必须是连续上升的, 不能是 升-降-升 ), 然后把差值相加
 * 由于数组 prices[] 是给定的, 我们相当于有了先知的预见能力
 * 如果明天的价格比今天高, 那就今天买进明天卖出, maxProfit += profit
 * 比如 [day2 > day1], [day3 > day2], 那么上面的算法可以获得 [day3 - day1] 的利润
 * 也就是 day1 买进, day2 卖出, 然后因为知道 day3 的价格比 day2 高, 那么 day2 重新买进, day3再卖出
 * 相当于 day1 买进, day3 卖出
 * ps: 无手续费
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxProfit = 0;
		int len = prices.size() - 1;	// 会用到[i+1], 所以i的范围是[0, i-1), 而不是[0, i-1]
		for( int i = 0; i < len; i++ ){
			// 有预见能力, 可以知道明天的价格是否高于今天的价格
			if( prices[i+1] > prices[i] ){
				maxProfit += prices[i+1] - prices[i];
			}
		}
		return maxProfit;
	}
};

