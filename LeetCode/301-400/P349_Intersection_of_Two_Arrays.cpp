/*
https://leetcode.com/problems/intersection-of-two-arrays/description/
给定两个数组（可能包含重复元素），求其交集
同类题目 P349, P350

思路
1. 使用集合容器unordered_set, 先对两个数组去重
2. 依次对比两个set，找出共同元素

参考
1. [unordered_set](http://www.cplusplus.com/reference/unordered_set/unordered_set/?kw=unordered_set)

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;

		if( nums1.size() == 0 || nums2.size() == 0 ){
			return ans;
		}

		unordered_set<int> uset1(nums1.begin(), nums1.end());
		unordered_set<int> uset2(nums2.begin(), nums2.end());

		if( uset1.size() < uset2.size() ){
			for( auto it : uset1 ){
				if( uset2.find(it) != uset2.end() ){
					ans.push_back(it);
				}
			}
		}else{
			for( auto it : uset2 ){
				if( uset1.find(it) != uset1.end() ){
					ans.push_back(it);
				}
			}
		}
		return ans;
	}
};

int main(){
	Solution s;
	vector<int> v1, v2, v3;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(2);
	v2.push_back(2);
	v3 = s.intersection(v1, v2);
	for(auto item : v3){
		cout<<item<<' ';
	}
	cout<<'\n';
	return 0;
}
