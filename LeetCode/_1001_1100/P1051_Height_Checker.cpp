/*
https://leetcode.com/problems/height-checker/description/

同类题目 P1051
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution{
public:
	int heightChecker(vector<int>& heights){
		vector<int> tmp = heights;
		sort(tmp.begin(), tmp.end());
		int ans = 0;
		int len = tmp.size();
		for( int i = 0; i < len; i++ ){
			if( tmp[i] != heights[i] ){
				ans++;
			}
		}
		return ans;
	}
};