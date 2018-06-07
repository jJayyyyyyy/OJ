/*
 * https://leetcode.com/problems/reverse-bits/description/
 * 给定一个32位无符号数, 对其进行二进制意义上的翻转
 * 如32位的二进制数 0000 .... 0001, 将变成 1000 .... 0000 
 * 同类题目 P190, P191
 * 
 * 参考: https://leetcode.com/problems/reverse-bits/discuss/54741/O(1)-bit-operation-C++-solution-(8ms)
 * 有点像归并排序过程的相反顺序
 * 32 位太长, 下面以 8 位为例, 如 n = abcd efgh, 其中 a~h 每一个字母都代表 0 或 1
 * Step 1: abcd efgh --> efgh abcd, 以 4 位位单位进行翻转
 *         n1 = ( n & 1111 0000 ) >> 4 --> abcd 0000
 *         n2 = ( n & 0000 1111 ) << 4 --> 0000 efgh
 *         n  = n1 | n2 --> efgh abcd
 *
 * Step 2: ef gh  ab cd --> gh ef  cd ab
 *         n1 = ( n & 1100 1100 ) >> 2 --> 00 ef 00 ab
 *         n2 = ( n & 0011 0011 ) << 2 --> gh 00 cd 00
 *         n  = n1 | n2 --> gh ef cd ab
 *
 * Step 3: gh ef  cd ab --> hg fe  dc ba, 同理可得
 *
*/

// #include <iostream>
// #include <vector>
// #define uint32_t unsigned int
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		n = ( n >> 16 ) | ( n << 16 );	// shift 16
		n = ( (n & 0xff00ff00) >> 8 ) | ( (n & 0x00ff00ff) << 8 );	// shift 8
		n = ( (n & 0xf0f0f0f0) >> 4 ) | ( (n & 0x0f0f0f0f) << 4 );	// shift 4
		n = ( (n & 0xcccccccc) >> 2 ) | ( (n & 0x33333333) << 2 );	// shift 2
		n = ( (n & 0xaaaaaaaa) >> 1 ) | ( (n & 0x55555555) << 1 );	// shift 1
		return n;
	}
};


int main(){
	Solution s;
	uint32_t n = 43261596;
	uint32_t ans = s.reverseBits(n);
	cout<<ans<<'\n';

	return 0;
}

