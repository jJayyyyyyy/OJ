/*
 * https://leetcode.com/problems/maximum-subarray/description/
 * 最大连续子列和
 * 同类题目
 * 
 * 状态的无后效性 --- 以A[i]结尾
 * 边界 dp[0] = A[0]
 * 状态转移方程 dp[i] = max( A[i], dp[i-1] + A[i] )
 *
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp(len, 0);

		dp[0] = nums[0];

		for( int i = 1; i < len; i++ ){
			dp[i] = max(nums[i], dp[i-1] + nums[i]);
			
		}

		// 若要进一步加速, 可以把两个for循环进行合并
		int maxID = 0;
		for( int i = 1; i < len; i++ ){
			if( dp[i] > dp[maxID] ) {
				maxID = i;
			}
		}

		return dp[maxID];
	}
};


// int main(){
// 	Solution s;

// 	vector<int> nums;
// 	nums.push_back(-2);
// 	nums.push_back(1);
// 	nums.push_back(-3);
// 	nums.push_back(4);
// 	nums.push_back(-1);
// 	nums.push_back(2);
// 	nums.push_back(1);
// 	nums.push_back(-5);
// 	nums.push_back(4);
// 	cout<<s.maxSubArray(nums)<<'\n';	// 6

// 	nums.clear();
// 	nums.push_back(-2);
// 	nums.push_back(11);
// 	nums.push_back(-4);
// 	nums.push_back(13);
// 	nums.push_back(-5);
// 	nums.push_back(-2);
// 	cout<<s.maxSubArray(nums)<<'\n';	// 20
// 	return 0;
// }
