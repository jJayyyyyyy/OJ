/*
https://leetcode.com/problems/check-if-it-is-a-straight-line/description/?goto=old

输入平面上的一些点的坐标 vector<vector<int> > & coordinates
判断这些点是否共线

同类题目 P1232

k1 = (y2 - y1)/(x2 - x1)
k2 = (y3 - y1)/(x3 - x1)

共线的话， k1 == k2
为了避免 k 不存在的情况，把分子乘上来
即， 若 (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)
则 p1, p2, p3 共线
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int> > & coordinates) {
        vector<int> & coord1 = coordinates[0];
        int x1 = coord1[0];
        int y1 = coord1[1];
        vector<int> & coord2 = coordinates[1];
        int x2 = coord2[0];
        int y2 = coord2[1];
        
        bool vertical = false, isStraitLine = false;

        for ( int i = 2; i < coordinates.size(); i++ ) {
            vector<int> & coord3 = coordinates[i];
            int x3 = coord3[0];
            int y3 = coord3[1];
            if ( (y2 - y1) * (x3 - x1) != (y3 - y1) * (x2 - x1) ) {
                return false;
            }
        }
        return true;
    }
};

