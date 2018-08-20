/*
https://leetcode.com/problems/hamming-distance/description/
位运算
同类题目: P461

给定两个正整数，计算他们之间有多少个二进制位是不同的

思路很简单
先异或，留下不同的位为1

然后判断最低位是否为1
再右移1位
如此循环32次
*/

#include <iostream>
using namespace std;

class Solution{
public:
	int hammingDistance(int x, int y){
		int z = x ^ y;
		int ans = 0;
		int mask = 1;
		for( int i = 0; i < 32; i++ ){
			if( z & mask != 0 ){
				ans++;
			}
			z = z >> 1;
		}
		return ans;
	}
};

int main(){
	Solution s;

	// 0001 vs 0100
	cout<<s.hammingDistance(1, 4)<<'\n';
	// 0001 vs 0001
	cout<<s.hammingDistance(1, 1)<<'\n';

	// 0001 vs 0010
	cout<<s.hammingDistance(1, 2)<<'\n';

	// 0001 vs 0011
	cout<<s.hammingDistance(1, 3)<<'\n';
	return 0;
}
