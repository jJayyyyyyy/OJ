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
		string ans = "";
		bool positive = true;
		if( num < 0 ){
			num = -num;
			positive = false;
		}

		int quotient=0, remain=0;
		while(true){
			quotient = num / 7;
			remain = num % 7;
			ans += to_string(remain);
			if( quotient == 0 ){
				break;
			}
            num = quotient;
		}
		if( positive == false ){
			ans += "-";
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};