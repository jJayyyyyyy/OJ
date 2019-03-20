/*
https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
给出一组排好序的字符 letters, 找到比目标字符 target 大的第一个字符 ans
注意, 在和目标字符进行比较的时候, 其大小是循环连接的(wrap around)
Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
同类题目 P744

*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	char nextGreatestLetter(vector<char> & letters, char target) {
		char ans = '#';
		for( char ch : letters )
		{
			if( ch > target )
			{
				ans = ch;
				break;
			}
		}
		if( ans == '#' )
		{
			ans = letters[0];
		}
		return ans;
	}
};