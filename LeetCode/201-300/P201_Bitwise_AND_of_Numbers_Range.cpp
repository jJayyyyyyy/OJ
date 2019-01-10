/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
给出一个正整数区间, 对区间里的每一个数进行按位与操作，返回最后的结果
同类题目 P201

参考思路
https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/56746/One-line-C++-solution
Consider the bits from low to high. if n > m, the lowest bit will be 0, and then we could transfer the problem to sub-problem: rangeBitwiseAnd(m>>1, n>>1).

int rangeBitwiseAnd(int m, int n) {
    return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
}



另外，在按照参考思路写非递归代码的时候，总是出现问题，然后看到了排名第一的代码，发现这个问题还可以进一步简化，也就是下面的参考代码的思路(self-explanatory)

*/

#include <iostream>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int cnt = 0;
		while( m != n ){
			cnt++;
			m >>= 1;
			n >>= 1;
		}
		
		return m<<cnt;
	}
};

int main(){
	Solution s;
	
	// cout<<s.rangeBitwiseAnd(5, 7);
	// cout<<s.rangeBitwiseAnd(2, 2);
	// cout<<s.rangeBitwiseAnd(4, 5);
	// cout<<s.rangeBitwiseAnd(0, 0);
	// cout<<s.rangeBitwiseAnd(0, 2147483647);
	return 0;
}