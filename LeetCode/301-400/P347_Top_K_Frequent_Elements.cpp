/*
https://leetcode.com/problems/top-k-frequent-elements/description/
统计出现次数最多的元素
同类题目 P347, P973, P977

*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution{
public:
	struct KeyCnt{
		int key, cnt;
		KeyCnt(int k, int c){
			key = k;
			cnt = c;
		}

		bool operator < (const KeyCnt & a) const {
			return cnt > a.cnt;
		}
	};

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for( int key : nums ){
			m[key]++;
		}
		
		vector<KeyCnt> kcList;
		for( auto item : m ){
			int key = item.first;
			int cnt = item.second;
			KeyCnt kc(key, cnt);
			kcList.push_back(kc);
		}

		sort(kcList.begin(), kcList.end());
		vector<int> ans(k);
		for( int i = 0; i < k; i++ ){
			ans[i] = kcList[i].key;
		}
		return ans;
	}
};