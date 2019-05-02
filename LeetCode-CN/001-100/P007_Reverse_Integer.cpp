/*
https://leetcode-cn.com/classic/problems/two-sum/description/
反转整数, 溢出则返回 0

*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// const static auto c = []() {
// 	std::ios::sync_with_stdio(false);
// 	std::cin.tie(0);
// 	return 0;
// }();

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


int main()
{
	Solution s;
	cout << s.reverse(123) << '\n';
	cout << s.reverse(-123) << '\n';
	cout << s.reverse(120) << '\n';
	cout << s.reverse(-2147483648) << '\n';
	return 0;
}
