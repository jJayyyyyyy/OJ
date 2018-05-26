/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 * 给出股票走势, 何时买入, 何时卖出, 利润最大
 * 同类题目 P121, P122
 * 
 * 
 * 思路: 同Solution
 * 维护两个变量: 最小价格minprice, 最大利润maxprofit
 * 遍历的时候更新minprice, 这样不用回溯就可以知道minprice
 * 当前利润profit = 当前价格prices[i] - minprice
 * 若当前利润大于最大利润maxprofit, 则更新最大利润
 * 延伸一下, 还可以记录minprice 和 maxprofit 出现的时间
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
	int maxProfit(vector<int> & prices) {
		int minprice = 0x3fff0000;
		int maxprofit = 0;
		// int minDay, maxDay;
		for( int i = 0; i < prices.size(); i++ ){
			if( prices[i] < minprice )
			{
				minprice = prices[i];
				// minDay = i;
			}
			// 注意是 if-elif 的关系
			// 也就是价格上升了, 才有利润
			else if( prices[i] - minprice > maxprofit ){
				maxprofit = prices[i] - minprice;
				// maxDay = i;
			}
		}
		return maxprofit;
	}
};

// int main(){
// 	Solution s;

// 	vector<int> v;
// 	v.push_back(7);
// 	v.push_back(1);
// 	v.push_back(5);
// 	v.push_back(3);
// 	v.push_back(6);
// 	v.push_back(4);
	
// 	cout<<s.maxProfit(v)<<'\n';
// 	v.clear();

// 	v.push_back(7);
// 	v.push_back(6);
// 	v.push_back(4);
// 	v.push_back(3);
// 	v.push_back(1);

// 	cout<<s.maxProfit(v)<<'\n';

// 	return 0;
// }