/*
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 * 求帕斯卡三角阵/杨辉三角阵
 * 同类题目 P118, P119
 * 
 * 思路: 与P118完全相同
 * 注意: 行数从0开始计数
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
	vector<int> getRow(int rowIndex) {
		vector<int> preLine;
		if( rowIndex >= 0 ){
			preLine.push_back(1);
			for( int row = 0; row < rowIndex; row++ ){
				vector<int> line;
				line.push_back(1);
				for( int col = 1; col < preLine.size(); col++ ){
					int num = preLine[col - 1] + preLine[col];
					line.push_back(num);
				}
				line.push_back(1);
				preLine = line;
				
			}
		}
		return preLine;
	}
};

// int main(){
// 	Solution s;

// 	vector<int> line = s.getRow(0);
	
// 	for( auto num : line ){
// 		cout<<num<<' ';
// 	}
// 	cout<<'\n';

// 	line = s.getRow(3);
	
// 	for( auto num : line ){
// 		cout<<num<<' ';
// 	}
// 	cout<<'\n';

// 	return 0;
// }
