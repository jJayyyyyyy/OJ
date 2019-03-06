/*
https://leetcode.com/problems/contains-duplicate/description/
寻找数组中第 k 大的整数
*/
// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
using std::greater;

class Solution {
public:
	int findKthLargest(vector<int> & nums, int k) {
		sort(nums.begin(), nums.end());
		int ans = nums[nums.size() - k];
		return ans;
	}
};

class Solution2 {
public:
	int findKthLargest(vector<int> & nums, int k) {
		priority_queue<int> pq;
		for( int num : nums )
		{
			pq.push(num);
		}

		int ans;
		for( int i = 0; i < k; i++ )
		{
			ans = pq.top();
			pq.pop();
		}
		return ans;
	}
};
