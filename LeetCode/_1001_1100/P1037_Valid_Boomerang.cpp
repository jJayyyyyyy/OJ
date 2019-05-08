/*
https://leetcode.com/problems/valid-boomerang/description/
判断三个点能否组成三角形 ( 不共线 )
同类题目 P1037, P812

参考思路
https://leetcode.com/problems/valid-boomerang/discuss/286702/JavaC++Python-Straight-Forward
https://leetcode.com/problems/largest-triangle-area/discuss/122711/C++JavaPython-Solution-with-Explanation-and-Prove
*/

#include <iostream>
#include <string>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	bool isBoomerang(vector<vector<int>>& points) {
		int x0 = points[0][0];
		int y0 = points[0][1];
		int x1 = points[1][0];
		int y1 = points[1][1];
		int x2 = points[2][0];
		int y2 = points[2][1];

		int area2 = x0 * y1 + x1 * y2 + x2 * y0 - x0 * y2 - x1 * y0 - x2 * y1;
		return area2 != 0;
	}

	bool isBoomerang2(vector<vector<int>> & points){
		int x0 = points[0][0];
		int y0 = points[0][1];
		int x1 = points[1][0];
		int y1 = points[1][1];
		int x2 = points[2][0];
		int y2 = points[2][1];

		// (y1 - y0)/(x1 - x0) != (y2 - y1) / (x2 - x1)
		// 防止斜率不存在, 两边同乘分母
		return (y1 - y0) * (x2 - x1) != (y2 - y1) * (x1 - x0);
	}
};

