/*
https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/
数组 A 的大小为 2N, 其中 N 个元素只出现 1 次, 只有 1 个元素 num 重复出现了 N 次, 求num
同类题目 P961

使用 unordered_set 记录已经出现的元素, 根据题意, 第一个重复出现的元素就是答案
*/

#include <iostream>
#include <unordered_set>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	int repeatedNTimes(vector<int> & A) {
		unordered_set<int> s;
		int ans = A[0];
		for( int num : A ){
			if( s.find(num) != s.end() ){
				ans = num;
				break;
			}else{
				s.insert(num);
			}
		}
		return ans;
	}
};
