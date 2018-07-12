/*
https://leetcode.com/problems/power-of-four/description/
判断一个正整数( [0, 2^32] ) 是否为 4 的指数
同类题目 P342

思路:
1. num 是正数
2. num 是 2 的指数
3. num 是 4 的指数
*/

#include <iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		if( num < 1 ){
			return false;
		}else if( num == 1 ){
			return true;
		}else if( ( num & (num-1) ) != 0 ){
			// 如果是 2 的指数那么其二进制只有最高位的一个 1
			// 比如 1d -> 1b
			// 2d -> 10b
			// 4d -> 100b
			// 8d -> 1000b
			// 16d -> 10000b
			// 那么，num-1 就是 011111 之类的
			// 因此 ( num & (num-1) ) 就是 0
			return false;
		}else if( ( num & 0x55555555 ) != num  ){
			// 如果是 4 的指数，那么 num 首先是2的指数，此时 num 只有最高位的一个 1
			// 其次，num 中的 1 必须在奇数位
			// 比如，1d -> 1b (第1位)
			// 4d -> 100b	(第3位)
			// 16d -> 10000b (第5位)
			// 因此用 mask, 把偶数位的全都盖掉，只留下奇数位，然后和原来的数字进行对比
			// mask 可以用 0101 0101 0101 0101 0101 0101 0101 0101 0101 ... b (32位)
			// 也就是 0x5555 5555
			return false;
		}else{
			return true;
		}
	}
};
