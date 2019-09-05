/*
https://leetcode.com/problems/valid-sudoku/description/?goto=old
数独

同类题目 P036

参考思路
https://leetcode.com/problems/valid-sudoku/discuss/15464/My-short-solution-by-C++.-O(n2)
https://leetcode.com/problems/valid-sudoku/discuss/15472/Short+Simple-Java-using-Strings

使用三个数组，分布记录 某row, 某col, 某subboxIndex 是否存在当前格子里的 digit
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool rowHasNum[9][10] = {false};
		bool colHasNum[9][10] = {false};
		bool subboxHasNum[9][10] = {false};
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {
				char ch = board[row][col];
				if (ch != '.') {
					int digit = ch - '0';

					if (rowHasNum[row][digit] == true) {
						return false;
					}
					rowHasNum[row][digit] = true;

					if (colHasNum[col][digit] == true) {
						return false;
					}
					colHasNum[col][digit] = true;

					int subboxIndex = row / 3 * 3 + col / 3;
					if (subboxHasNum[subboxIndex][digit] == true) {
						return false;
					}subboxHasNum[subboxIndex][digit] = true;
				}
			}
		}
		return true;
	}
};
