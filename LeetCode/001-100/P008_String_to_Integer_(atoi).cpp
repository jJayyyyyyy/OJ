/*
https://leetcode.com/problems/string-to-integer-atoi/description/?goto=old
实现 atoi
同类题目 P1103

> "it's not algorithm,it's a if-else practice"
> by Pyloons, https://leetcode.com/problems/string-to-integer-atoi/discuss/4640/Such-a-shitty-problem

先去掉前导0
然后读取可能的正负号，除此以外，如果出现了非数字，则返回 0
然后读取随后的数字，如果出现了非数字，则丢掉随后的内容，然后开始转换
转换的时候要注意，题目限制了只能使用 32位 的有符号数
如果出现了溢出，那么这个Solution将被认为是错误的答案
因此要在
INT_MAX / 10
INT_MIN / 10
的地方就开始判断，防止溢出
*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int ans = 0, digit = 0, sign = 1, i = 0, len = str.size();
		char ch;
		for (i = 0; i < len; i++) {
			ch = str[i];
			if (ch != ' ') {
				break;
			}
		}

		if (ch == '+') {
			sign = 1;
		}
		else if (ch == '-') {
			sign = -1;
		}
		else if (ch >= '0' && ch <= '9') {
			digit = ch - '0';
			ans = sign * digit;
		}
		else{
			return 0;
		}
		i++;
		int uplimit = INT_MAX / 10;    // INT_MAX / 10 == 214748364
		int downlimit = INT_MIN / 10; // INT_MIN / 10 == -214748364
		while(i < len){
			ch = str[i++];
			if (ch >= '0' && ch <= '9') {
				digit = ch - '0';
				if (sign == 1) {
					if (ans < uplimit) {
						ans = ans * 10 + digit;
					}
					else if (ans == uplimit) {
						ans = ans * 10;
						if (INT_MAX - ans > digit) {
							ans += digit;
						}
						else {
							ans = INT_MAX;
							break;
						}
					}
					else {
						ans = INT_MAX;
						break;
					}
				}
				else {
					if (ans > downlimit) {
						ans = ans * 10 - digit;
					}
					else if (ans == downlimit) {
						ans = ans * 10;
						if (ans - INT_MIN > digit) {
							ans -= digit;
						}
						else {
							ans = INT_MIN;
							break;
						}
					}
					else {
						ans = INT_MIN;
						break;
					}
				}
			}
			else {
				break;
			}
		}
		return ans;
	}
};


int main(){
	Solution s;
	cout << s.myAtoi("42") << '\n';    // 42
	cout << s.myAtoi("-42") << '\n';   // -42
	cout << s.myAtoi("   -42") << '\n';// -42
	cout << s.myAtoi("4193 with words") << '\n';    // 4193
	cout << s.myAtoi("words and 987") << '\n';    // 0
	cout << s.myAtoi("-91283472332") << '\n';    // -2147483648
	cout << s.myAtoi("100000000000000000") << '\n';    // 2147483647
	cout << s.myAtoi("2147483648") << '\n';    // 2147483647
	return 0;
}
