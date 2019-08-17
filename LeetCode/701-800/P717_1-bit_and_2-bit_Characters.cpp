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

/*
解法2
从后往前

We don't need to traverse the whole array, just check the last part of it.

1. if there is only one symbol in array the answer is always true (as last element is 0)
2. if there are two 0s at the end again the answer is true no matter what the rest symbols are( ...1100, ...1000,)
3. if there is 1 right before the last element(...10), the outcome depends on the count of sequential 1, i.e.
	a) if there is odd amount of 1(10, ...01110, etc) the answer is false as there is a single 1 without pair
	b) if it's even (110, ...011110, etc) the answer is true, as 0 at the end doesn't have anything to pair with

https://leetcode.com/problems/1-bit-and-2-bit-characters/solution/
https://leetcode.com/problems/1-bit-and-2-bit-characters/discuss/108967/JAVA-check-only-the-end-of-array
*/

class Solution2 {
	public boolean isOneBitCharacter(int[] bits) {
		int ones = 0;
		//Starting from one but last, as last one is always 0.
		for (int i = bits.length - 2; i >= 0 && bits[i] != 0 ; i--) { 
			ones++;
		}
		if (ones % 2 > 0) return false; 
		return true;
	}
};
