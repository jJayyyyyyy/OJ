/*
https://leetcode-cn.com/classic/problems/two-sum/description/
反转整数, 溢出则返回 0

*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// const static auto c = []() {
// 	std::ios::sync_with_stdio(false);
// 	std::cin.tie(0);
// 	return 0;
// }();

class Solution {
public:
	int reverse(int x) {
		#define MAXINT 0x7fffffff
		#define MININT 0x80000000

		if( x == MININT )
		{
			return 0;
		}

		bool negative = false;
		if( x < 0 )
		{
			negative = true;
			x = -x;
		}
		string s;
		stringstream ss1;
		ss1 << x;
		ss1 >> s;
		std::reverse(s.begin(), s.end());
		stringstream ss2(s);
		long long rev_num;
		ss2 >> rev_num;

		if( rev_num > MAXINT )
		{
			return 0;
		}
		else
		{
			int ans = (int)rev_num;
			if( negative == true )
			{
				ans = -ans;
			}
			return ans;
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
