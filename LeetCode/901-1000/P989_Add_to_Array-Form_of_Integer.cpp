/*
https://leetcode.com/problems/add-to-array-form-of-integer/description/
大整数相加, 先 reverse, 从最低位开始相加, 并记录进位 carry, 最后再次 reverse 得到答案
同类题目 P989
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	vector<int> addToArrayForm(vector<int> & A, int k) {
		vector<int> num2;
		while( k != 0 )
		{
			int remain = k % 10;
			num2.push_back(remain);
			k /= 10;
		}
		vector<int> num1 = A;
		reverse(num1.begin(), num1.end());

		int len1 = num1.size();
		int len2 = num2.size();
		int len3 = len1 < len2 ? len1 : len2;
		vector<int> ans;
		int carry = 0;
		for( int i = 0; i < len3; i++ )
		{
			int res = num1[i] + num2[i] + carry;
			if( res >= 10 )
			{
				carry = 1;
				res %= 10;
			}
			else
			{
				carry = 0;
			}

			ans.push_back(res);
		}

		if( len1 > len3 )
		{
			for( int i = len3; i < len1; i++ )
			{
				int res = num1[i] + carry;
				if( res >= 10 )
				{
					carry = 1;
					res %= 10;
				}
				else
				{
					carry = 0;
				}

				ans.push_back(res);
			}
		}
		else
		{
			for( int i = len3; i < len2; i++ )
			{
				int res = num2[i] + carry;
				if( res >= 10 )
				{
					carry = 1;
					res %= 10;
				}
				else
				{
					carry = 0;
				}

				ans.push_back(res);
			}
		}
		if( carry == 1 )
		{
			ans.push_back(1);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main()
{
	Solution s;
	vector<int> A(3);
	A[0] = 2;
	A[1] = 1;
	A[2] = 5;
	int k = 806;
	s.addToArrayForm(A, k);
	return 0;
}
