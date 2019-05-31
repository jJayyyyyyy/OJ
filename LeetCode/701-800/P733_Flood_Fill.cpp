/*
https://leetcode.com/problems/flood-fill/description/
Flood Fill, 类似 BFS
同类题目 P733
*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

struct MyPoint{
	int r, c;
	MyPoint(int x, int y){
		r = x;
		c = y;
	}
};
class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>> & image, int sr, int sc, int newColor) {
		queue<MyPoint> q;
		q.push(MyPoint(sr, sc));
		int oldcolor = image[sr][sc];
		if( oldcolor != newColor ){
			int nRows = image.size();
			int nCols = image[0].size();

			while( q.size() ){
				MyPoint p = q.front();
				q.pop();
				int r = p.r;
				int c = p.c;
				image[r][c] = newColor;

				if( c - 1 >= 0 && image[r][c - 1] == oldcolor ){
					q.push(MyPoint(r, c - 1));
				}
				if( c + 1 < nCols && image[r][c + 1] == oldcolor ){
					q.push(MyPoint(r, c + 1));
				}
				if( r - 1 >= 0 && image[r -1][c] == oldcolor ){
					q.push(MyPoint(r - 1, c));
				}
				if( r + 1 < nRows && image[r + 1][c] == oldcolor ){
					q.push(MyPoint(r + 1, c));
				}
			}
		}

		return image;
	}
};