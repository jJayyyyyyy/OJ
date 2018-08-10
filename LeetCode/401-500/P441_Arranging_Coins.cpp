/*
https://leetcode.com/problems/arranging-coins/description/
寻找最小的 row，使得 1 + 2 + 3 + 4 + ... + row >= n
同类题目 P441, 
*/

#include <iostream>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();


// struct TreeNode {
// 	int val;
// 	TreeNode *left, *right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL){}
// };


class Solution{
public:
	int arrangeCoins(int n) {
		int row = 1;
		while( n >= row ){
			n -= row;
			row++;
		}
		return row - 1;
	}
};
