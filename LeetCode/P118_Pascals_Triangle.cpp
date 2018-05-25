/*
 * https://leetcode.com/problems/pascals-triangle/description/
 * 求帕斯卡三角阵/杨辉三角阵
 * 同类题目 P118, P119
 * 
 * 思路: 分类讨论
 * numRows <= 0, 无
 * numRows == 1, 1
 * numRows > 1 , 每一行都可以由上面一行得到
*/

// #include <iostream>
// #include <vector>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

// Solution
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int> > ans;
		if( numRows > 0 ){
			vector<int> line1;
			line1.push_back(1);
			ans.push_back(line1);
			for( int row = 1; row < numRows; row++ ){
				vector<int> line;
				line.push_back(1);
				int prevRow = row - 1;
				for( int col = 1; col < ans[prevRow].size(); col++ ){
					int num = ans[prevRow][col - 1] + ans[prevRow][col];
					line.push_back(num);
				}
				line.push_back(1);
				ans.push_back(line);
			}
		}
		return ans;
	}
};

// int main(){
// 	Solution s;

// 	vector< vector<int> > ans = s.generate(5);

// 	for( auto line : ans ){
// 		for( auto num : line ){
// 			cout<<num<<' ';
// 		}
// 		cout<<'\n';
// 	}

// 	return 0;
// }
