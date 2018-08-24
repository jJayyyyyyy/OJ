/*
https://leetcode.com/problems/max-consecutive-ones/description/
给定一个只含 0 或 1 的数组，统计其最长连续 1 的个数
同类题目: P485

思路
末尾加上结束符
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int findMaxConsecutiveOnes(vector<int> & nums) {
		int cnt=0, maxCnt=0;
		nums.push_back(-1);
		for( int i = 0; i < nums.size(); i++ ){
			if( nums[i] == 1 ){
				cnt++;
			}else{
				if( cnt > maxCnt ){
					maxCnt = cnt;
				}
				cnt = 0;
			}
		}
		return maxCnt;
	}
};

int main(){
	Solution s;

	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);

	cout<<s.findMaxConsecutiveOnes(nums)<<'\n';

	return 0;
}
