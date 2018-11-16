/*
https://leetcode.com/problems/binary-number-with-alternating-bits/description/
给一个 int 整数, 写出其二进制表示, 判断相邻的位是否相同
同类题目 P693

注意, 判断相邻只截取到最高有效的1, 更高位的0忽略不计

1 ---    1 --- true
4 ---  100 --- false
5 ---  101 --- true
7 --- 0111 --- false

*/

#include <iostream>
using namespace std;

class Solution {
public:
	bool hasAlternatingBits(int n) {
		n = n & 0x7fffffff;		// 去掉符号位, 可以忽略, 因为题目输入的是正整数
		int lastBit1 = n & 1;
		n = n>>1;
		while( n != 0 ){
			int lastBit2 = n & 1;
			if( lastBit1 == lastBit2 ){
				// 若最低两位相同, 则返回 false
				return false;
			}
			lastBit1 = lastBit2;
			n = n >> 1;
		}
		return true;
	}
};

int main(){
	Solution s;
	cout<<s.hasAlternatingBits(1)<<'\n';
	cout<<s.hasAlternatingBits(4)<<'\n';
	cout<<s.hasAlternatingBits(5)<<'\n';
	cout<<s.hasAlternatingBits(7)<<'\n';
	
	return 0;
}