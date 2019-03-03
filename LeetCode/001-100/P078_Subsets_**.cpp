/*
https://leetcode.com/problems/subsets/description/

同类题目 P078, P090, P046

参考思路
https://leetcode.com/problems/subsets/discuss/27278/C++-RecursiveIterativeBit-Manipulation
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector< vector<int> > subsets(vector<int> & nums) {
		vector< vector<int> > ans = {{}};
		for( int num : nums ){
			int len = ans.size();
			for( int i = 0; i < len; i++ ){
				ans.push_back(ans[i]);
				ans.back().push_back(num);
			}
		}
		return ans;
	}
};