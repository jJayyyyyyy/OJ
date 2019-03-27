/*
https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/discuss/260885/C++-6-lines-O(n)-target-sum
给定一个数组， 所有元素的和是 sum, 判断它能否唯一地按顺序分成三个子数组, 每个子数组的和 part_sum == sum / 3
同类题目 P1020

参考思路
https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/discuss/260885/C++-6-lines-O(n)-target-sum
http://www.cplusplus.com/reference/numeric/accumulate/?kw=accumulate
*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	bool canThreePartsEqualSum(vector<int> & A) {
		int sum = accumulate(A.begin(), A.end(), 0);
		if( sum % 3 != 0 ){
			return false;
		}
		else{
			sum /= 3;
			int size = A.size();
			int part_sum = 0;
			int cnt = 0;
			int i = 0;
			while( i < size ){
				part_sum += A[i];
				if( part_sum == sum ){
					cnt++;
					part_sum = 0;
				}
				i++;
			}
			return cnt == 3;
		}
	}
};
