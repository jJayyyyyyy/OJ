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
			vector<int> preLine;
			preLine.push_back(1);
			ans.push_back(preLine);
			for( int row = 1; row < numRows; row++ ){
				vector<int> line;
				line.push_back(1);
				for( int col = 1; col < preLine.size(); col++ ){
					int num = preLine[col - 1] + preLine[col];
					line.push_back(num);
				}
				line.push_back(1);
				preLine = line;
				ans.push_back(preLine);
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
