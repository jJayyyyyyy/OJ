/*
https://leetcode.com/problems/ugly-number/description/
给定一个整数, 判断是否为正数, 并判断它是否包含{2, 3, 5}以外的质因数
同类题目 P263

思路:
不断除掉 {2, 3, 5} 因子, 直到不能整除为止, 最后判断 商 是否为 1
*/

#include <iostream>
using namespace std;

class Solution{
public:
	bool isUgly(int num){
		if( num < 1 ){
			return false;
		}else if( num == 1 ){
			return true;
		}else{
			for( int i = 2; i <= 5; i++ ){
				while( num % i == 0 ){
					num /= i;
				}
			}
			return num == 1;
		}
	}
};


