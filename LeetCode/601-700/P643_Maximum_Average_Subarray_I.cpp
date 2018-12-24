/*
https://leetcode.com/problems/maximum-average-subarray-i/description/
求长度为 k 的连续子序列的和的最大值
同类题目 P643

*/

#include <iostream>
#include <vector>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
	double findMaxAverage(vector<int> & nums, int k) {
		int len = nums.size();
		int sum = 0;
		for( int i = 0; i < k; i++ ){
			sum += nums[i];
		}
		int ans = sum;
		for( int i = k; i < len; i++ ){
			sum += nums[i] - nums[i-k];
			if( sum > ans ){
				ans = sum;
			}
		}
		return ans * 1.0 / k;
	}
};