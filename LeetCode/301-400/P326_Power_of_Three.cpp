/*
https://leetcode.com/problems/power-of-three/description/
判断一个数是否为3的指数
同类题目 P326

注意:
1 是 3 的 0 次方
*/

#include <iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		if( n == 1 ){
			return true;
		}else if( n < 3 ){
			return false;
		}else{
			while( n % 3 == 0 ){
				n /= 3;
			}
			
			return n == 1;
		}
	}
};
