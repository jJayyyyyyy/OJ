/*
https://leetcode.com/problems/rectangle-overlap/description/
判断两个矩形是否重叠
同类题目 P846, P223

参考思路1
参考P223, 求矩形交集的面积 intersection_area
若 intersection_area > 0, 则矩形相交

参考思路2
https://leetcode.com/problems/rectangle-overlap/solution/
Approach #1: Check Position
*/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		int A = rec1[0];
		int B = rec1[1];
		int C = rec1[2];
		int D = rec1[3];
		int E = rec2[0];
		int F = rec2[1];
		int G = rec2[2];
		int H = rec2[3];
		int left = max(A,E);
		int right = max(min(C,G), left);
		int bottom = max(B,F);
		int top = max(min(D,H), bottom);
		long long area = (long long) (right - left) * (long long) (top - bottom);
		return abs(area) > 0;
	}
};
