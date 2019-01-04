/*
https://leetcode.com/problems/maximum-product-of-three-numbers/description/
找出数组中的 3 个数, 使其乘积最大
同类题目 P628

参考思路
https://leetcode.com/problems/maximum-product-of-three-numbers/solution/
*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

#define MAX 0x3fffffff
class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int min1 = MAX, min2 = MAX;
		int max1 = -MAX, max2 = -MAX, max3 = -MAX;
		for( int n : nums ){
			if( n <= min1 ){
				// min1 是最小的
				min2 = min1;
				min1 = n;
			}else if( n <= min2 ){
				min2 = n;
			}

			if( n >= max1 ){
				// max1 是最大的
				max3 = max2;
				max2 = max1;
				max1 = n;
			}else if( n >= max2 ){
				max3 = max2;
				max2 = n;
			}else if( n >= max3 ){
				max3 = n;
			}
		}
		int ans = max( min1 * min2 * max1, max1 * max2 * max3 );
		return ans;
	}
};