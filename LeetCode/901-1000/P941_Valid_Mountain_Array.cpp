/*
https://leetcode.com/problems/valid-mountain-array/description/?goto=old
判断一个数组是否为一个山形数组
即
1.	A.length >= 3
2.	存在 0 < i < A.length, 使得
	A[0] < A[1] < ... A[i-1] < A[i]
	A[i] > A[i+1] > ... > A[A.length - 1]
即 0~i 升序，i~length-1 降序

同类题目 P941

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
	bool validMountainArray(vector<int>& A) {
		int len = A.size();
		if (len <= 2) {
			return false;
		}

		bool ascend = false, descend = false;
		int i = 1;

		while (i < len) {
			if (A[i] > A[i - 1]) {
				ascend = true;
				i++;
			}
			else {
				break;
			}
		}

		while (i < len) {
			if (A[i] < A[i - 1]) {
				descend = true;
				i++;
			}
			else {
				break;
			}
		}
		return ascend && descend && i == len;
	}
};

int main() {
	int arr[] = {1, 3, 2};
	vector<int> a(arr, arr+3);
	Solution s;
	s.validMountainArray(a);

	return 0;
}