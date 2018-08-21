/*
https://leetcode.com/problems/number-complement/description/
位运算
同类题目: P476, P461

给定1个 signed int num (32 bit), 对其按位取反, 注意 32 bit 二进制形式的 num 的前导 0 不要取反

以 8 位 为例, 如 5 = (101)
0000 0101

【期望答案】是
0000 0010

如果直接用 ~num, 则会计入前导 0, 则结果是
1111 1010


参考思路
https://leetcode.com/problems/number-complement/discuss/96017/3-line-C++

既然不考虑前导0，
那么我们可以先数出有多少个前导0，设为n
然后对num取反，numR
再把 numR 的前 n 位用0覆盖掉即可
*/

#include <iostream>
using namespace std;

class Solution {
public:
	int findComplement(int num) {
		int mask = 0xffffffff;		// 32位全1
		while(num & mask){
			mask <<= 1;				// 右移低位补零
		}
		// 循环结束后，mask就变成了 num 高位的 1
		return (~mask & ~num);
	}
};
