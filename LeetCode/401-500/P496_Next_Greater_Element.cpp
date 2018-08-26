/*
https://leetcode.com/problems/next-greater-element-i/description/
给定一个数组 nums 以及它的子集 findNums
对于 findNums 中的每一个元素 ele，先定位到它在 nums 中对应的位置，然后向后寻找第一个比 ele 更大的数
同类题目: P496

参考思路
https://leetcode.com/problems/next-greater-element-i/discuss/97613/C++-stack-+-unordered_map
http://www.cplusplus.com/reference/unordered_map/unordered_map/find/

如果用循环遍历，可能会达到 O(n^2) 的复杂度
我们通过 stack 和 unordered_map 建立索引表 m，使得 m[n] 存储的是 n 的 next greater element
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		stack<int> s;
		unordered_map<int, int> m;
		// 建立索引，nge = m[n] , neg 存储了 n 的 next greater element
		for( int n : nums ){
			while( s.size() && s.top() < n ){
				m[s.top()] = n;
				s.pop();
			}
			s.push(n);
		}

		vector<int> ans;
		for( int fn : findNums ){
			if( m.find(fn) != m.end() ){
				ans.push_back(m[fn]);
			}else{
				ans.push_back(-1);
			}
		}
		
		return ans;
	}
};