/*
https://leetcode.com/problems/last-stone-weight/description/
一个数组, 每次将最大的两个数相减 diff = max1 - max2, 如果 diff != 0, 则把 diff 放回数组
如此重复直到数组中只剩一个数或者变成空数组
同类题目 P1046

参考思路
优先队列/最大堆
https://leetcode.com/problems/last-stone-weight/discuss/295005/Java-Simplest-Easiest-Priority-Queue

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		// 不能用 set, 因为会去重
		priority_queue<int> pq(stones.begin(), stones.end());
		while( pq.size() > 1 ){
			int max1 = pq.top();
			pq.pop();
			int max2 = pq.top();
			pq.pop();
			int diff = max1 - max2;
			if( diff > 0 ){
				pq.push(diff);
			}
		}
		return pq.size() == 1 ? pq.top() : 0;
	}
};