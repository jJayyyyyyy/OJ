/*
https://leetcode.com/problems/smallest-range-i/description/
同类题目 P908
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int smallestRangeI(vector<int> & A, int K){
		int minval = 10000, maxval = 0;
		for( size_t i = 0; i < A.size(); i++ ){
			if( minval > A[i] ){
				minval = A[i];
			}

			if( maxval < A[i] ){
				maxval = A[i];
			}
		}

		int ans = maxval - minval - 2 * K;
		if( ans < 0 ){
			return 0;
		}else{
			return ans;
		}
	}
};

int main() {
	Solution s;
	vector<int> A(2, 0);
	A[0] = 0;
	A[1] = 10;
	s.smallestRangeI(A, 2);

	return 0;
}