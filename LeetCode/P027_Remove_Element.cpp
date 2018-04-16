/*
 * https://leetcode.com/problems/remove-element/
 * 去掉值为val的元素
 *
*/

// #include <iostream>
// #include <vector>
// using namespace std;


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int head = 0;
		for( int i = 0; i < nums.size(); i++ ){
			if( nums[i] != val ){
				nums[head], nums[i];
				head++;

			}
		}
		return head;
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
// 	nums.push_back(0);
// 	nums.push_back(4);
// 	nums.push_back(2);
// 	cout<<s.removeElement(nums, 2)<<'\n';
// 	for( auto num : nums ){
// 		cout<<num<<' ';
// 	}
// 	cout<<'\n';


// 	return 0;
// }
