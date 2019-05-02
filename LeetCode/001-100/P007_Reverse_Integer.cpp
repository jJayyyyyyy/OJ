/*
https://leetcode.com/problems/reverse-integer/description/
给定一个整数，倒序输出。若超出32位有符号整数的范围，则返回0

*/

#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
	int reverse(int x){
		std::string s = std::to_string(x);
		if( s[0] == '-' ){
			std::reverse(s.begin()+1, s.end());
		}else{
			std::reverse(s.begin(), s.end());
		}
		long long res = std::stoll(s);
		
		if( res < -0x7fffffff-1 || res > 0x7fffffff ){
			return 0;
		}else{
			return (int)res;
		}
	}
};

/*
int main(){
	Solution s;
	std::cout<<s.reverse(-1563847412);
	return 0;
}
*/