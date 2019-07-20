/*
https://leetcode.com/problems/n-th-tribonacci-number/description/?goto=old
计算三元的斐波那契数列
同类题目 P1137

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int tribonacci(int n) {
		long long trib[40];
		trib[0] = 0;
		trib[1] = 1;
		trib[2] = 1;
		for (int i = 3; i <= n; i++) {
			trib[i] = trib[i - 1] + trib[i - 2] + trib[i - 3];
		}
		return trib[n];
	}
};
