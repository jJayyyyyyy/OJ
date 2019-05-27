/*
https://leetcode.com/problems/rotting-oranges/description/
BFS
同类题目 P994

参考思路
https://leetcode.com/problems/rotting-oranges/discuss/238670/BFS-C++-with-clear-explanation-(-8-ms-100-)
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
	int i, j;
	MyPoint(int x, int y){
		i = x;
		j = y;
	}
};

class Solution{
public:
	int orangesRotting(vector<vector<int> > & grid) {
		queue<MyPoint> q;
		int nRows = grid.size();
		int nCols = grid[0].size();
		int freshOrange = 0;

		for( int i = 0; i < nRows; i++ ){
			for( int j = 0; j < nCols; j++ ){
				int orange = grid[i][j];
				if( orange == 2 ){
					q.push(MyPoint(i, j));
				}
				else if( orange == 1 ){
					freshOrange++;
				}
			}
		}

		int cnt = 0;
		while( q.size() ){
			int len = q.size();
			bool hasRottenOrange = false;

			while( len-- ){
				MyPoint point = q.front();
				int i = point.i;
				int j = point.j;
				q.pop();

				if( i - 1 >= 0 && grid[i-1][j] == 1 ){
					grid[i-1][j] = 2;
					q.push(MyPoint(i-1, j));
					hasRottenOrange = true;
					freshOrange--;
				}
				if( i + 1 < nRows && grid[i+1][j] == 1 ){
					grid[i+1][j] = 2;
					q.push(MyPoint(i+1, j));
					hasRottenOrange = true;
					freshOrange--;
				}
				if( j - 1 >= 0 && grid[i][j-1] == 1 ){
					grid[i][j-1] = 2;
					q.push(MyPoint(i, j-1));
					hasRottenOrange = true;
					freshOrange--;
				}
				if( j + 1 < nCols && grid[i][j+1] == 1 ){
					grid[i][j+1] = 2;
					q.push(MyPoint(i, j+1));
					hasRottenOrange = true;
					freshOrange--;
				}
			}
			if( hasRottenOrange == true ){
				cnt++;
			}
			
		}
		return freshOrange == 0 ? cnt : -1;
	}
};