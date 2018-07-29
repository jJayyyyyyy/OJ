/*
https://leetcode.com/problems/third-maximum-number/description/
找到第三大的数
同类题目 P414

注意边界条件，可能会检测 int 的最小值
所以要把变量的范围扩大到long long
要使用<climits>中的 LLONG_MIN

http://www.cplusplus.com/reference/climits/
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long long first = LLONG_MIN;
		long long second = LLONG_MIN;
		long long third = LLONG_MIN;

		for( int n : nums ){
			if( n > first ){
				third = second;
				second = first;
				first = n;
			}else if( n < first && n > second ){
				third = second;
				second = n;
			}else if( n < second && n > third ){
				third = n;
			}
		}

		if( third == LLONG_MIN ){
			return (int)first;
		}else{
			return (int)third;
		}
	}
};
