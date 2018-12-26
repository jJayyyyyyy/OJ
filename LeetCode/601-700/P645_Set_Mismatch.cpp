/*
https://leetcode.com/submissions/detail/196744566/

同类题目 P645
*/

#include <iostream>
#include <vector>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		int len = nums.size();
		vector<int> bitmap(len + 1, 0);
		for( int num : nums ){
			bitmap[num]++;
		}
		int dup, miss;
		for( int i = 1; i <= len; i++ ){
			if( bitmap[i] == 2 ){
				dup = i;
			}else if( bitmap[i] == 0 ){
				miss = i;
			}
		}
		vector<int> ans;
		ans.push_back(dup);
		ans.push_back(miss);
		return ans;
	}
};
