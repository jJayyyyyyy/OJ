/*
https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/
一个数组 A, (可能)有正有负, 对其中的 k 个数取相反数(可以作用于同一个元素), 求这样操作过后 sum(A.begin(), A.end(), 0) 能取得的最大值
同类题目 P1005

参考思路
https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/discuss/252254/C++Python-Sort
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// const static auto c = []() {
// 	std::ios::sync_with_stdio(false);
// 	std::cin.tie(0);
// 	return 0;
// }();

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int k) {
		sort(A.begin(), A.end());
		int n = A.size();
		int i = 0;
		for( ; i < n && i < k; i++ ){
			int num = A[i];
			if( num < 0 ){
				A[i] = -num;
			}
			else{
				break;
			}
		}
		int sum = 0;
		int minval = A[0];
		for( int num : A ){
			if( minval > num ){
				minval = num;
			}
			sum += num;
		}

		sum -= ( (k - i) % 2 ) * minval * 2;

		return sum;
	}
};

int main(){
	Solution s;
	vector<int> A(3);
	A[0] = 4;
	A[1] = 2;
	A[2] = 3;
	int k = 1;
	s.largestSumAfterKNegations(A, k);
	return 0;
}
