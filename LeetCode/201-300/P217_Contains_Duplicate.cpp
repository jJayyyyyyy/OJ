/*
 * https://leetcode.com/problems/contains-duplicate/description/
 * 判断数组中是否存在重复元素
 * 同类题目 P217
 * 
 * 方法1: hash, unordered_set
 * 方法2: 先排序, 然后前后比较
*/

// #include <iostream>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	// hash
	bool containsDuplicate_1(vector<int>& nums){
		unordered_set<int> s;
		for( auto n : nums ){
			if( s.find(n) == s.end() ){
				s.insert(n);
			}else{
				return true;
			}
		}
		return false;
	}

	// sort
	bool containsDuplicate_2(vector<int> & nums){
		int len = nums.size();
		if( len < 2 ){
			return false;
		}

		sort(nums.begin(), nums.end());
		for( int i = 1; i < len; i++ ){
			if( nums[i-1] == nums[i] ){
				return true;
			}
		}
		return false;
	}
	
	bool containsDuplicate(vector<int> & nums){
		return containsDuplicate_1(nums);
		// return containsDuplicate_2(nums);
	}
};


int main(){
	Solution s;

	vector<int> n;
	n.push_back(1);
	n.push_back(2);
	n.push_back(3);
	n.push_back(4);
	cout<<s.containsDuplicate(n)<<'\n';


	n.push_back(1);
	cout<<s.containsDuplicate(n)<<'\n';

	return 0;
}