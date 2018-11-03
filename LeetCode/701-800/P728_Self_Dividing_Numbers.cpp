/*
https://leetcode.com/problems/self-dividing-numbers/description/
给定一个区间 [left, right],
判断其中的每个数 num 是否能被它自身的所有 digit 整除
同类题目 P728
*/

#include <iostream>
#include <string>
using namespace std;

// 可以优化的地方很多
// 减少函数调用
// 不需要 to_string(), 直接 %
// 不过会减少可读性
class Solution {
public:
	bool isDivisible(int num){
		string s = to_string(num);
		bool flag = true;
		for( char ch : s ){
			int digit = ch - '0';
			if( digit == 0 ){
				flag = false;
				break;
			}else if( num % digit != 0 ){
				flag = false;
				break;
			}
		}
		return flag;
	}

	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ans;

		for( int i = left; i <= right; i++ ){
			if( isDivisible(i) ){
				ans.push_back(i);
			}
		}
		return ans;
	}
};