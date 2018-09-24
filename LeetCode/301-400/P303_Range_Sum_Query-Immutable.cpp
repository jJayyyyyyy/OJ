/*
https://leetcode.com/problems/range-sum-query-immutable/description/
数组片段求和
同类题目 P303, P304, P307

注意:
本题可以假设数组不会改变，可以假设 i 和 j 不会超出数组下标范围
一组测试中会多次调用 sumRange(), 因此需要一个数组存储 从 0 到 cur 的和 curSum[j+1]，这样可以直接用 curSum[j+1] - curSum[i] 来获得答案，而不是每次重新累加
*/

#include <iostream>
#include <vector>
using namespace std;

static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class NumArray{
private:
	vector<int> curSum;
public:
	NumArray(vector<int> nums){
		// int sum = 0;
		int len = nums.size();
		curSum.resize(len+1, 0);
		for( int i = 0; i < len; i++ ){
			// sum += n;
			curSum[i+1] = curSum[i] + nums[i];	// 不要用 sum, 根据局部性原理，用 curSum[i] 会比用其他地方的 sum 快一些，同时也和 P304 的写法一致
		}
	}

	int sumRange(int i, int j){
		return curSum[j+1] - curSum[i];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */