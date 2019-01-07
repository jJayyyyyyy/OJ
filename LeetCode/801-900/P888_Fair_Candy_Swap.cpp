/*
https://leetcode.com/problems/fair-candy-swap/description/
从 A 中选出一个数 barA, 从 B 中选出一个数 barB, 交换 barA 和 barB, 使得 sumA == sumB
同类题目 P888
*/

#include <iostream>
#include <unordered_set>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	vector<int> fairCandySwap(vector<int> & A, vector<int> & B) {
		int sumA = 0, sumB = 0;
		vector<int> ans(2);
		unordered_set<int> sA;

		for( int barA : A ){
			sumA += barA;
			sA.insert(barA);
		}

		for( int barB : B ){
			sumB += barB;
		}

		int halfDelta = (sumA - sumB) / 2;

		for( int barB : B ){
			int barA = barB + halfDelta;
			if( sA.find(barA) != sA.end() ){
				ans[0] = barA;
				ans[1] = barB;
				break;
			}
		}
		return ans;
	}
};
