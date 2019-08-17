/*
https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
前缀编码
符号 c1 被编码为 0
符号 c2 被编码为 10 或 11
也就是说, 10 应被理解为 [10], 110 应被理解为 [11] [0]

给出一串以 0 结尾的编码，判断最后的 0 是否一定属于 c1 (被解码成 c1)
同类题目 P717

参考思路
https://leetcode.com/problems/1-bit-and-2-bit-characters/solution/
*/

#include <iostream>
#include <string>
using namespace std;

/*
解法1
从前往后
遇到了 1 肯定要进 2 位
遇到了 0 肯定要进 1 位
就这样一直进位，然后看下标能不能到 len - 1
https://leetcode.com/problems/1-bit-and-2-bit-characters/solution/
https://leetcode.com/problems/1-bit-and-2-bit-characters/discuss/109008/Easy-to-understand-C++-solution-with-modified-for-loop
*/

class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int i = 0;
		int len = bits.size();
		int end = len - 1;
		while (i < end) {
			if (bits[i] == 1) {
				i += 2;
			}
			else {
				i += 1;
			}
		}
		return i == end;
	}
};
