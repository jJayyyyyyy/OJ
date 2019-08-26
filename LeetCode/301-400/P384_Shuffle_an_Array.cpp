/*
https://leetcode.com/problems/shuffle-an-array/description/goto=old
实现 shuffle, 即把数组元素顺序打乱
同类题目 P384

参考思路
https://leetcode.com/problems/shuffle-an-array/solution/
http://www.cplusplus.com/reference/cstdlib/rand/?kw=rand
rand() 的使用需要 stdlib.h
*/

#include <iostream>
#include <cstdlib>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
private:
	vector<int> original_arr;
	vector<int> shuffled_arr;
	int len;

public:
	Solution(vector<int>& nums) {
		original_arr = nums;
		shuffled_arr = nums;
		len = nums.size();
	}
	
	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return original_arr;
	}

	int get_rand_index(int begin) {
		return rand() % (len - begin) + begin;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		for (int i = 0; i < len; i++) {
			int rand_index = get_rand_index(i);
			swap(shuffled_arr[i], shuffled_arr[rand_index]);
		}
		return shuffled_arr;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */