/*
https://leetcode.com/problems/base-7/description/
进制转换
同类题目 P501

思路:
除r取余
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
	string convertToBase7(int num){
		bool isPositive = true;
		if( num < 0 ){
			num = -num;
			isPositive = false;
		}

		string ans = "";
		int remain;
		do{
			remain = num % 7;
			ans += (remain + '0');
			num /= 7;
		}while(num != 0);
		reverse(ans.begin(), ans.end());
		if( isPositive == false ){
			ans = '-' + ans;
		}
		return ans;
	}
};