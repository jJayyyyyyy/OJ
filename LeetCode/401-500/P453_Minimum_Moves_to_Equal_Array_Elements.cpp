/*
https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
数学题，解方程
设初始数列 nums 的和为 s0, 且 nums 的长度为 len, 再设 nums 中最小的元素值是 minval
需要 k 个 move 才能使最终序列 final_nums 变成每个元素都相等的序列
final_nums 的和为 s1, 且 final_nums 的均值为 avg, 那么
s1 = s0 + (len - 1) * k
avg = s1 / len
minval + k = avg
===>
minval + k = s1 / len = (s0 + (len - 1) * k) / len
minval * len = s0 - k
k = s0 - minval * len

参考思路
https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/183193/topic
https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/93817/It-is-a-math-question
*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

class Solution {
public:
	int minMoves(vector<int>& nums) {
		long long minval = 0x3fffffff;
		long long s0 = 0;
		int len = nums.size();
		if( len <= 1 ){
			return 0;
		}
		for( int val : nums ){
			if( val < minval ){
				minval = val;
			}
			s0 += val;
		}
		int k = int(s0 - minval * len);
		return k;
	}
};