/*
https://leetcode.com/problems/distribute-candies/description/
有 2n 个糖果, 分给哥哥和妹妹, 每人 n 个糖果
问妹妹最多能分到多少【不同种类的】糖果
同类题目 P585
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// const static auto c = []() {
// 	std::ios::sync_with_stdio(false);
// 	std::cin.tie(0);
// 	return 0;
// }();

class Solution{
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int> s;
		int len = candies.size();
		int halflen = len / 2;
		for(int i = 0; i < len; i++ ){
			s.insert(candies[i]);
		}

		if( s.size() >= halflen ){
			return halflen;
		}else{
			return s.size();
		}
	}
};


int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	Solution s;
	vector<int> v(6);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 1;
	v[4] = 2;
	v[5] = 3;
	s.distributeCandies(v);

	return 0;
}

