/*
https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
有一个无序序列，求其连续递增子序列的最大长度
同类题目 P674

思路:
设定另外一个数组 record
record[i] 记录了以 nums[i] 为终点时的连续递增序列的长度
最后遍历 record, 求出最大的 maxlen = record[i] 即可

改进:
不需要额外的数组, 在遍历 nums 的时候同步更新 maxlen 即可
*/

#include <iostream>
using namespace std;

const static auto c = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution1 {
public:
	vector<int> record;
	int findLengthOfLCIS(vector<int>& nums) {
		int len = nums.size();
		if( len == 0 ){
			return 0;
		}
		record.resize(len, 1);
		for( int i = 1; i < len; i++ ){
			int n1 = nums[i-1];
			int n2 = nums[i];
			if( n1 < n2 ){
				record[i] = record[i-1] + 1;
			}
		}
		int maxlen = 1;
		for( int i = 1; i < len; i++ ){
			if( maxlen < record[i] ){
				maxlen = record[i];
			}
		}
		return maxlen;
	}
};

class Solution2 {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int len = nums.size();
		if( len == 0 ){
			return 0;
		}
		int cnt = 1;
		int maxlen = 1;
		for( int i = 1; i < len; i++ ){
			int n1 = nums[i-1];
			int n2 = nums[i];
			if( n1 < n2 ){
				cnt++;
				if( maxlen < cnt ){
					maxlen = cnt;
				}
			}else{
				cnt = 1;
			}
		}
		return maxlen;
	}
};