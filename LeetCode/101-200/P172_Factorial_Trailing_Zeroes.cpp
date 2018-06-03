/*
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 * 求 阶乘 n! 的后缀零 0 的个数
 * 同类题目 P172
 * 
 * 
 * 思路1: 数学规律题, 阶乘 n! 后缀中的 0 来自于因子 5 和 2 的乘积
 * 更进一步可以发现, 由于因子 2 总是足够的(0~4之间有2和4, 5~9之间有6和8), 所以 0 的个数就是因子 5 的个数
 * 
*/

// #include <iostream>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	int trailingZeroes(int n) {
		int cntFive = 0;
		while( n > 0 ){
			n /= 5;
			cntFive += n;
		}
		return cntFive;
	}
};