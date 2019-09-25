/*
https://leetcode.com/problems/minimum-time-visiting-all-points/description/?goto=old

同类题目 P1266

先沿对角线，到达与下一个点 x 或 y 坐标相同的地方，然后沿 X 轴或 Y 轴到达下一个点
实际上就是求 max(y_distance, x_distance);

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector< vector<int> > & points) {
        int cnt = 0;
        int length = points.size();
        vector<int> & p0 = points[0];
        int x0 = p0[0];
        int y0 = p0[1];
        for ( int i = 1; i < length; i++ ) {
            vector<int> & p1 = points[i];
            int x1 = p1[0];
            int y1 = p1[1];
            int x_distance = abs(x1 - x0);
            int y_distance = abs(y1 - y0);
            cnt += max(y_distance, x_distance);
            x0 = x1;
            y0 = y1;
        }
        return cnt;
    }
};
