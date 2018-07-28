/*
https://leetcode.com/problems/third-maximum-number/description/
找到第三大的数
同类题目 P414

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		int first = INT_MIN;
		int second = INT_MIN;
		int third = INT_MIN;

		for( int n : nums ){
			if( n > first ){
				third = second;
				second = first;
				first = n;
			}else if( n > second ){
				third = second;
				second = n;
			}else if( n > third ){
				third = n;
			}
		}

		if( third == INT_MIN ){
			return first;
		}else{
			return third;
		}
	}
};
