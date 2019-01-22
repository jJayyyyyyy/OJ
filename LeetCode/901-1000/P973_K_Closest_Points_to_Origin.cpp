/*
https://leetcode.com/problems/k-closest-points-to-origin/description/
输入一组坐标, 输出距离原点最近的K个点(使用欧氏距离)

同类题目 P973, P977
*/

#include <iostream>
#include <vector>
#include <algoritm>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution{
public:
	struct Point{
		int x, y, dist;
		Point(int a, int b){
			x = a;
			y = b;
			dist = x * x + y * y;
		}
		bool operator < (const Point & a) const {
			return dist < a.dist;
		}
	};

	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		vector<Point> pList;

		for( vector<int> item : points ){
			Point p(item[0], item[1]);
			pList.push_back(p);
		}

		sort(pList.begin(), pList.end());

		vector< vector<int> > ans;
		for( int i = 0; i < K; i++ ){
			vector<int> line(2);
			line[0] = pList[i].x;
			line[1] = pList[i].y;
			ans.push_back(line);
		}

		return ans;
	}
};

int main() {
	Solution s;
	vector<vector<int>> v;
	vector<int> line(2);
	line[0] = 1;
	line[1] = 3;
	v.push_back(line);
	line[0] = -2;
	line[1] = 2;
	v.push_back(line);

	s.kClosest(v, 1);

	return 0;
}
