/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 * 去掉值为有序表中重复的元素
 *
*/

// #include <iostream>
// #include <vector>
// using namespace std;


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if( len == 0 ){
			return 0;
		}else{
			int head = 0;
			for( int i = 0; i < len; i++ ){
				if( nums[i] != nums[head] ){
					head++;
					nums[head] = nums[i];
				}
			}
			return head+1;
		}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;
// 	vector<int> nums;
// 	nums.push_back(0);
// 	nums.push_back(1);
// 	nums.push_back(2);
// 	nums.push_back(2);
// 	nums.push_back(3);
// 	nums.push_back(4);
// 	nums.push_back(5);
// 	cout<<s.removeDuplicates(nums)<<'\n';
// 	for( auto num : nums ){
// 		cout<<num<<' ';
// 	}
// 	cout<<'\n';


// 	return 0;
// }
