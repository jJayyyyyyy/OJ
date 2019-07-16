/*
https://leetcode.com/problems/defanging-an-ip-address/description/?goto=old
为 ip 地址的
同类题目 P1108

思路:
水题

注:
fang 的意思是尖牙，哈利波特里面海格养的大狗叫牙牙，英文原著中的名字是 Fang
defang 就是拔去尖牙，使无害，使无效
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string defangIPaddr(string address) {
		string ans = "";
		for (char ch : address) {
			if (ch != '.') {
				ans += ch;
			}
			else {
				ans += "[.]";
			}
		}
		return ans;
	}
};