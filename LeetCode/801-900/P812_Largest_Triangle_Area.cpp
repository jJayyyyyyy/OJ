/*
https://leetcode.com/problems/largest-triangle-area/description/
给一组点, 求能组成的面积最大的三角形的面积
同类题目 P812, P976, P1037

参考思路
https://leetcode.com/problems/largest-triangle-area/solution/


求三角形面积
area = abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2.0;
矩阵形式

area = | 1  1  1  |  x 1/2
       | x1 x2 x3 |
       | y1 y2 y3 |

https://en.wikipedia.org/wiki/Shoelace_formula
*/

#include <iostream>
#include <vector>
using namespace std;

static int ioSpeedUp=[](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
	double largestTriangleArea(vector<vector<int>>& points) {
		int len = points.size();
		double ans = 0;
		for( int i = 0; i < len; i++ ){
			double x1 = points[i][0];
			double y1 = points[i][1];
			for( int j = i + 1; j < len; j++ ){
				double x2 = points[j][0];
				double y2 = points[j][1];
				for( int k = j + 1; k < len; k++ ){
					double x3 = points[k][0];
					double y3 = points[k][1];
					
					double area = abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
					ans = max(ans, area);
				}
			}
		}
		return ans / 2.0;
	}
};