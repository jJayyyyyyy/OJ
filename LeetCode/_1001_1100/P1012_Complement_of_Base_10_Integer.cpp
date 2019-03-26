/*
https://leetcode.com/problems/complement-of-base-10-integer/description/
位操作, 去掉 n 的二进制的所有前导 0 , 然后取反, 所以关键是找到有多少个前导 0
同类题目 P1012

参考思路
https://leetcode.com/problems/complement-of-base-10-integer/description/
*/

#include <iostream>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

// 从后往前找
class Solution1
{
public:
	int bitwiseComplement(int n)
	{
		int mask = 1;
		while( mask <= n )
		{
			mask = (mask << 1) + 1;
		}
		n = (~n) & mask;
		return n;
	}
};

// 从前往后找
class Solution2
{
public:
	int bitwiseComplement(int n) {
		// 假设 n 是正数
		int mask = 0x80000000;
		for( int i = 0; i < 32; i++ )
		{
			if( (mask & n) != 0 )
			{
				break;
			}
			else
			{
				leading_zero++;
				mask >>= 1;
			}
		}
		mask = ~mask;
		mask = (mask << 1) + 1;
		n = (~n) & mask;
		return n;
	}
};



int main()
{
	Solution s;
	s.bitwiseComplement(5);
	return 0;
}
