/*
https://leetcode.com/problems/island-perimeter/description/
计算海岸线长度
同类题目: P463

参考链接: https://leetcode.com/problems/island-perimeter/discuss/95126/C++-solution-with-explanation

如果采用暴力求解，代码会比较长也比较丑，参考链接给出的思路就比较优雅了

首先，找到陆地，即 grid[i][j] == 1 ，如果不考虑周围的格子，那么这一个 grid[i][j] 就有长度为 4 的海岸线, cnt+4
接着，我们考虑到，如果 grid[i+1][j] 也是 1，那么他们之间有一条重合的边，而且这条边属于内陆，不是海岸线，所以 cnt-2

多么精巧的思路~


*/

#include <iostream>
#include <vector>
using namespace std;

static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution{
public:
	int islandPerimeter(vector< vector<int> > & grid) {
		int cnt = 0;
		for( int i = 0; i < grid.size(); i++ ){
			for( int j = 0; j < grid[i].size(); j++ ){
				if( grid[i][j] == 1 ){
					cnt += 4;
					if( i != 0 && grid[i-1][j] == 1 ){
						cnt -= 2;
					}
					if( j != 0 && grid[i][j-1] == 1 ){
						cnt -= 2;
					}
				}
			}
		}
		return cnt;
	}
	
	int islandPerimeterFaster(vector< vector<int> > & grid) {
		int cntIsland = 0, cntRepeat = 0;
		for( int i = 0; i < grid.size(); i++ ){
			for( int j = 0; j < grid[i].size(); j++ ){
				if( grid[i][j] == 1 ){
					cntIsland++;
					if( i != 0 && grid[i-1][j] == 1 ){
						cntRepeat++;
					}
					if( j != 0 && grid[i][j-1] == 1 ){
						cntRepeat++;
					}
				}
			}
		}
		return cntIsland * 4 - cntRepeat * 2;
	}
};

int main(){
	Solution s;
	int r1[] = {0, 1, 0, 0};
	int r2[] = {1, 1, 1, 0};
	int r3[] = {0, 1, 0, 0};
	int r4[] = {1, 1, 0, 0};
	vector<int> rv1(r1, r1+4);
	vector<int> rv2(r2, r2+4);
	vector<int> rv3(r3, r3+4);
	vector<int> rv4(r4, r4+4);
	
	vector< vector<int> > grid;
	grid.push_back(rv1);
	grid.push_back(rv2);
	grid.push_back(rv3);
	grid.push_back(rv4);
	
	
	cout<<s.islandPerimeter(grid)<<'\n';


	return 0;
}

/*
0,1,0,0
1,1,1,0
0,1,0,0
1,1,0,0


*/
