/*
https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
给定两个字符串数组l1, l2，找出 s1 = l1[i]，以及 s2 = l2[j]，使得 s1 == s2，且 sum = i + j 尽量小
同类题目 P599
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		int len1 = list1.size();
		int len2 = list2.size();
		unordered_map<string, int> m;
		
		int sum = 0x3fffffff;
		vector<string> ans;
		for( int i = 0; i < len1; i++ ){
			m[list1[i]] = i;
		}
		for( int i = 0; i < len2; i++ ){
			if( m.find(list2[i]) != m.end() ){
				if( sum > i + m[list2[i]] ){
					ans.clear();
					ans.push_back(list2[i]);
					sum = i + m[list2[i]];
				}else if( sum == i + m[list2[i]] ){
					ans.push_back(list2[i]);
				}
			}
		}
		return ans;
	}
};