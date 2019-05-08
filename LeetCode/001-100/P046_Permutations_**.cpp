/*
https://leetcode.com/problems/permutations/description/
求全排列
同类题目 P078, P090, P046, P031, 20190508华为机考

参考思路:
找出 f(n-1) 和 f(n) 之间的关系

以 nums = [1, 2, 3] 为例
假设 f(n-1) 是 [ [1, 2], [2, 1] ], 也就是 [1, 2] 的全排列
那么 f(n) 就是在 f(n-1) 的基础上, 把 3 插入到每一个位置, 也就是说
[1, 2] 会分裂成
|--- [3, 1, 2]
|--- [1, 3, 2]
|--- [1, 2, 3]

而 [2, 1] 会分裂成
|--- [3, 2, 1]
|--- [2, 3, 1]
|--- [2, 1, 3]

因此可以得到 f(n) = [ [3, 1, 2], [1, 3, 2], [1, 2, 3], [3, 2, 1], [2, 3, 1], [2, 1, 3] ]
*/

#include <iostream>
#include <vector>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector< vector<int> > ans, tmpans;
		int len = nums.size();
		if( len > 1 ){
			ans.push_back(vector<int>(1, nums[0]));
			for( int i = 1; i < len; i++ ){
				int num = nums[i];
				for( vector<int> line : ans ){
					int len2 = line.size();
					for( int i = 0; i <= len2; i++ ){
						vector<int> tmpline = line;
						tmpline.insert(tmpline.begin() + i, num);
						tmpans.push_back(tmpline);
					}
				}
				ans = tmpans;
				tmpans.clear();
			}
		}
		return ans;
	}
};


// 使用 STL 的 next_permutation
// 首先对 nums 排序, 然后 do-while 调用 next_permutation()
class Solution2{
public:
	vector<vector<int>> permute(vector<int> & nums) {
		vector<vector<int>> anslist;
		sort(nums.begin(), nums.end());
		do{
			anslist.push_back(nums);
		}while(next_permutation(nums.begin(), nums.end()));

		return anslist;
	}
};


int main() {
	vector<int> nums(3);
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;

	Solution s;
	s.permute(nums);
	return 0;
}