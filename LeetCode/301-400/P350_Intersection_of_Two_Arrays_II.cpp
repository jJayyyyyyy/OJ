/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
给定两个数组（可能包含重复元素），求其交集(重复元素多次计数)
同类题目 P349, P350

思路
1. 先排序
2. 双指针前进

问题后面还有几个follow up，其中第3点是
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
我的想法是，把nums1的元素放入unordered_map，其中元素值作为key，出现次数作为value
然后分块提取nums2，查找map
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int len1 = nums1.size();
		int len2 = nums2.size();
		int i = 0, j = 0;
		vector<int> ans;
		while( i < len1 && j < len2 ){
			if( nums1[i] < nums2[j] ){
				i++;
			}else if( nums1[i] > nums2[j] ){
				j++;
			}else{
				ans.push_back(nums1[i]);
				i++;
				j++;
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
	v1.push_back(1);
	
	v2.push_back(2);
	v2.push_back(2);
	v3 = s.intersect(v1, v2);
	for(auto item : v3){
		cout<<item<<' ';
	}
	cout<<'\n';
	return 0;
}
