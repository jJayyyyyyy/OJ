/*
https://leetcode.com/problems/matrix-cells-in-distance-order/description/
BFS
同类题目 P1030

*/

#include <iostream>
#include <queue>
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
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		queue<MyPoint> q;
		q.push(MyPoint(r0, c0));
		vector< vector<int> > ans;
		bool vis[128][128] = {false};
		vis[r0][c0] = true;

		while( q.size() ){
			MyPoint p = q.front();
			int r = p.r;
			int c = p.c;
			q.pop();
			ans.push_back({r, c});

			if( c - 1 >= 0 && vis[r][c - 1] == false ){
				vis[r][c - 1] = true;
				q.push(MyPoint(r, c - 1));
			}
			if( c + 1 < C && vis[r][c + 1] == false ){
				vis[r][c + 1] = true;
				q.push(MyPoint(r, c + 1));
			}
			if( r - 1 >= 0 && vis[r - 1][c] == false ){
				vis[r - 1][c] = true;
				q.push(MyPoint(r - 1, c));
			}
			if( r + 1 < R && vis[r + 1][c] == false ){
				vis[r + 1][c] = true;
				q.push(MyPoint(r + 1, c));
			}
		}
		return ans;
	}
};

int main(){
	Solution s;
	vector<vector<int> > ans = s.allCellsDistOrder(1, 2, 0, 0);
	for( auto line : ans ){
		cout << line[0] << ' ' << line[1] << '\n';
	}
	return 0;
}