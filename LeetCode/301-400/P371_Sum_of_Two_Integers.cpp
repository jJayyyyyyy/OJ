/*
https://leetcode.com/problems/sum-of-two-integers/description/
不使用加号的情况下，完成2个整数的加法
同类题目 P371

参考1: https://leetcode.com/problems/sum-of-two-integers/discuss/84305/Share-my-C++-solutionseasy-to-understand
参考1: https://leetcode.com/problems/sum-of-two-integers/discuss/84283/0ms-AC-java-solution

思路:

1. 从二进制运算的角度考虑问题, 设
a = 2 = 0010
b = 7 = 0111

最终的结果是
a + b = 9 = 1001

2. 如果我们把每一位的相加与进位分开看，那么就是
  0010 + 0111
= 0101 + 0100(carry)
= 0001 + 1000(carry)
= 1001 + 0000(carry)


3. 可以发现，如果不看进位(carry)，那么左边其实就是异或运算 ^

0010 ^ 0111 = 0101
0101 ^ 0100 = 0001
0001 ^ 1000 = 1001


4. 接下来考虑进位

什么时候会出现进位呢？就是某一位都是1的情况，比如 01 和 01 会出现 10 的进位

这就相当于是 & 与运算，然后往左移动一位 << 1
1 & 1 = 1
1 & 0 = 0
0 & 0 = 0

当然这只是一种等效情况的判断，也就是某一位都是1时，
(a & b) << 1 === 等效于 === (a + b)的进位情况

举例而言
(0010 & 0111) << 1 = 0100(carry)
(0101 & 0100) << 1 = 1000(carry)
(0001 & 1000) << 1 = 0000(carry)

5. 因此，结合 异或^ 和 与& ，就可以实现 加法
*/

#include <iostream>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		int sum;
		while( b != 0 ){
			sum = a ^ b;
			b = ( a & b ) << 1;
			a = sum;
		}
		return sum;
	}
};

