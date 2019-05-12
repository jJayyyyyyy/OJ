/*
https://leetcode.com/problems/rectangle-area/description/
求两个矩形并集的面积

同类题目
P223, P836

参考思路
https://leetcode.com/problems/rectangle-area/discuss/62149/Just-another-short-way

总面积 = 矩形1面积 + 矩形2面积 - 重叠面积
left = max(A,E);
right = max(min(C,G), left);
bottom = max(B,F);
top = max(min(D,H), bottom);
*/

#include <iostream>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int left = max(A,E);
		int right = max(min(C,G), left);
		int bottom = max(B,F);
		int top = max(min(D,H), bottom);
		long long area1 = (C - A) * (D - B);
		long long area2 = (G - E) * (H - F);
		long long intersection = abs( (right - left) * (top - bottom) );
		return int(area1 + area2 - intersection);
	}
};
