/* 
https://leetcode.com/problems/container-with-most-water/description/
求出最大矩形面积

参考思路
https://leetcode.com/problems/container-with-most-water/solution/

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	int maxArea(vector<int> & height_list) {
		int area = 0;
		int left = 0;
		int right = height_list.size() - 1;
		while( left < right ){
			int len = right - left;
			int lH = height_list[left];
			int rH = height_list[right];
			int h = min(lH, rH);
			area = max(area, len * h);
			if( lH < rH ){
				left++;
			}
			else{
				right--;
			}
		}
		return area;
	}
};