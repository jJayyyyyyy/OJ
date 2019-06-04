/*
https://leetcode.com/problems/number-of-boomerangs/description/
判断哪几个点可以组成等边三角形, 注意点的顺序不同就是不同的组合方案
同类题目 P447

参考思路
https://leetcode.com/problems/number-of-boomerangs/discuss/92866/C++-clean-solution-O(n2).-Fully-commented-and-explained.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const static auto c = []() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int ans = 0;
		int len = points.size();
		for( int i = 0; i < len; i++ ){
			unordered_map<long long, int> map(len);
			int x1 = points[i][0];
			int y1 = points[i][1];
			for( int j = 0; j < len; j++ ){
				if( j != i ){
					int x2 = points[j][0];
					int y2 = points[j][1];
					int dx = x1 - x2;
					int dy = y1 - y2;
					long long dist = dx * dx + dy * dy;
					map[dist]++;
				}
			}
			for( auto & it : map ){
				int cnt = it.second;
				if( cnt > 1 ){
					ans += cnt * (cnt - 1);
				}
			}
		}
		return ans;
	}
};