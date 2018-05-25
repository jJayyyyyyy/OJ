/*
 * https://leetcode.com/problems/single-number/description/
 * 给定一个数组, 其中只有一个数是单独的, 其他所有的数都会出现2次. 找出那个单独的数
 * 同类题目 P136
 * 
 * 线性时间复杂度, 要求空间复杂度为O(1).
 * 思路: 异或, ^=
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = nums[0];
		int len = nums.size();
		for( int i = 1; i < len; i++ ){
			ans ^= nums[i];	// ^ 异或
		}
		return ans;
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;

// 	vector<int> n1, n2;
// 	n1.push_back(2);
// 	n1.push_back(2);
// 	n1.push_back(1);

// 	cout<<s.singleNumber(n1)<<'\n';

// 	n2.push_back(4);
// 	n2.push_back(1);
// 	n2.push_back(2);
// 	n2.push_back(1);
// 	n2.push_back(2);

// 	cout<<s.singleNumber(n2)<<'\n';

// 	return 0;
// }