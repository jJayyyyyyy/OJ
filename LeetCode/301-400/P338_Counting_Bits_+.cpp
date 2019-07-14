/*
https://leetcode.com/problems/counting-bits/description/
计算 [0, num] 中每个数的二进制表示中的 1 的个数
同类题目 P338

Follow up:
It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).

https://leetcode.com/submissions/detail/198281848/
*/

#include <iostream>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution1 {
public:
	vector<int> countBits(int num) {
		vector<int> ans;
		for( int i = 0; i <= num; i++ ){
			int cnt = 0;
			int tmp = i;
			while( tmp != 0 ){
				if( tmp & 1 != 0 ){
					cnt++;
				}
				tmp >>= 1;
			}
			ans.push_back(cnt);
		}
		return ans;
	}
};
