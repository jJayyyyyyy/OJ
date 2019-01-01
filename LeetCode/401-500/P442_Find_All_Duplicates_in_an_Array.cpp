/*
https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
找出数组中重复的元素
同类题目 P442

plus:
Could you do it without extra space and in O(n) runtime?
思路
观察 submission 中排名最高的答案可以发现, 如果不使用额外空间, 那就要借助符号位
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

static int ioSpeedUp=[](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

// Time: O(n)
// Space: O(n)
class Solution {
public:
	vector<int> findDuplicates(vector<int> & nums) {
		int len = nums.size();
		vector<bool> vis(len, false);
		vector<int> ans;

		for( int n : nums ){
			if( vis[n] == false ){
				vis[n] = true;
			}else{
				ans.push_back(n);
			}
		}
		return ans;
	}
};

// plus: no extra space and in O(n) runtime
class Solution {
public:
	vector<int> findDuplicates(vector<int> & nums) {
		int len = nums.size();
		vector<int> ans;

		for( int i = 0; i < len; i++ ){
			int tmp = nums[i];
			int ix = tmp >= 0 ? tmp : -tmp;
			if( nums[ix - 1] > 0 ){
				nums[ix - 1] = -nums[ix - 1];
			}else{
				ans.push_back(ix);
			}
		}
		return ans;
	}
};

