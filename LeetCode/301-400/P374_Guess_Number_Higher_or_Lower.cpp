/*
https://leetcode.com/problems/guess-number-higher-or-lower/description/
二分查找
同类题目 P367, P374

注意:
使用long long, 避免溢出

*/

#include <iostream>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		long long left = 1, right = n;
		if( guess(left) == 0 ){
			return left;
		}else if( guess(right) == 0 ){
			return right;
		}

		while( left <= right){
			long long mid = ( left + right ) / 2;
			if( guess(mid) == -1 ){
				right = mid - 1;
			}else if( guess(mid) == 1 ){
				left = mid + 1;
			}else{
				return mid;
			}
		}

		return 0;
	}
};
