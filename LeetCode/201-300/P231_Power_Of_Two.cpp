/*
 * https://leetcode.com/problems/power-of-two/description/
 * 判断一个数是否为 2 的幂
 * 同类题目 P231
 * 
 * 参考 https://leetcode.com/problems/power-of-two/discuss/63974/Using-nand(n-1)-trick
 * 首先这个数应该是正数
 * 其次, 如果 n 是 2 的幂, 那么其二进制形式只有 1 位是 1, 其他全都是 0
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
	bool isPowerOfTwo(int n) {
		if( n <= 0 ){
			return false;
		}else{
			return !( n & (n-1) );
		}
	}
};

