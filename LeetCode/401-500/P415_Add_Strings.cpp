/*
https://leetcode.com/problems/add-strings/description/
给定两个非负长整数，对其求和。不能使用库中的用于长整数相加的函数。
同类题目 P415


1. reverse, 从低位开始加, 记住carry
2. 先把短的加完, 再加上长的剩下的
3. 注意最后len2结束后, 可能存在carry=1的情况, 如 1 + 9 = 10
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		int len1 = num1.size();
		int len2 = num2.size();
		if( len1 > len2 ){
			swap(num1, num2);
			swap(len1, len2);
		}
		

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		string ans = "";
		int carry = 0;
		for( int i = 0; i < len1; i++ ){
			int a = num1[i] - '0';
			int b = num2[i] - '0';
			int sum = a + b + carry;
			if( sum >= 10 ){
				carry = 1;
				ans += sum - 10 + '0';
			}else{
				carry = 0;
				ans += sum + '0';
			}
		}

		for( int i = len1; i < len2; i++ ){
			int sum = num2[i] + carry - '0';
			if( sum >= 10 ){
				carry = 1;
				ans += sum - 10 + '0';
			}else{
				carry = 0;
				ans += sum + '0';
			}
		}

		if( carry == 1 ){
			ans += "1";
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};
