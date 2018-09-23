/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
给定一个无序数组 nums, 求 nums 的一个最短连续子数组 sub, 使得我们对 sub 进行排序后, 整个 nums 有序
同类题目 P581

参考题解: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/solution/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
方法1
复制 nums, 得到 mynums, 对 mynums 进行排序
从最左边开始, 对比 nums 和 mynums, 出现的第一处不同记为 left
从最右边开始, 对比 nums 和 mynums, 出现的第一处不同记为 right
left 和 right 中间的部分, 就是要求的 sub
*/
class Solution1{
public:
	int findUnsortedSubarray(vector<int> & nums){
		vector<int> mynums = nums;
		sort(mynums.begin(), mynums.end());
		int len = nums.size();
		int left = 0, right = len - 1;
		bool hasDiff = false;
		for( int i = 0; i < len; i++ ){
			if( nums[i] != mynums[i] ){
				left = i;
				hasDiff = true;
				break;
			}
		}

		for( int i = len - 1; i >= 0; i-- ){
			if( nums[i] != mynums[i] ){
				right = i;
				hasDiff = true;
				break;
			}
		}

		if( hasDiff == true ){
			return right - left + 1;
		}else{
			return 0;
		}
	}
};

/*
方法2, 选择排序
其实2的总体思路和1一样，都是要找到 left 和 right, 
使用栈来存储下标
首先从左到右遍历，每一次发现错位元素 nums[i] 时，对栈进行pop(), 直到 nums[i] 达到合适的位置，然后 s.push(i)
这个过程中，更新 left，即 left = min( left, s.top() )，从而找到最小的 left，即左边界

ps: 参考题解中说这种方法的时间复杂度是 O(n), 我认为值得商榷
比如当 nums = [1, 20, 21, 22, 23, 24, 4, 25, 26, 27, 28, 29, 30, 3, ...]

after you push the index of [1, 20, 21, 22, 23, 24] into the stack, it comes value 4, so you have to pop the index of [20, 21, 22, 23, 24],

similarly, if you want to push the index of value 3, you have to pop the index of [4, 25, 26, 27, 28, 29, 30]...

so basically, it takes O(n^2) time complexity, just as your solution mentioned, it's based on selective sort
*/
class Solution2{
public:
	// 选择排序，从左向右，把
	int findUnsortedSubarray(vector<int> & nums){
		int len = nums.size();

		stack<int> s1, s2;
		int left = len, right = 0;

		for( int i = 0; i < len; i++ ){
			while( s1.size() > 0 && nums[s1.top()] > nums[i] ){
				left = min( left, s1.top() );
				s1.pop();
			}
			s1.push(i);
		}

		for( int i = len - 1; i >= 0; i-- ){
			while( s2.size() > 0 && nums[s2.top()] < nums[i] ){
				right = max( right, s2.top() );
				s2.pop();
			}
			s2.push(i);
		}
		
		if( right - left > 0 ){
			return right - left + 1;
		}else{
			return 0;
		}
	}
};