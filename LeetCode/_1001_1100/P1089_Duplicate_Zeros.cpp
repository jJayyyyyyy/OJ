/*
https://leetcode.com/problems/duplicate-zeros/description/?goto=old
把数组中的0向后复制移位
input: [1,0,2,3,0,4,5,0]
after: [1,0,0,2,3,0,0,4,5,0,0]
final: [1,0,0,2,3,0,0,4]

要求不能开新数组，要原地(in place)复制移位
也就是直接从 input 到 final

同类题目 P1089

参考思路
双指针
https://leetcode.com/problems/duplicate-zeros/discuss/312727/C++Java-Two-Pointers-Space-O(1)

题目要求 in place，我们只需要用指针(下标) 来代表两个数组，而并不需要真正创建一个新的数组



首先数出 input 有 n 个 0
这样 after 的长度就是 input.size() + n
然后从后往前，逐个进行赋值（替换）
*/

#include <iostream>
#include <vector>
using namespace std;

// 下面的解法模拟了指针移动的过程
class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		int len = arr.size();
		int cntZero = count(arr.begin(), arr.end(), 0);
		if (cntZero == 0) {
			return;
		}

		int p1 = len - 1;
		int p2 = len - 1 + cntZero;
		while (p1 >= 0) {
			int val = arr[p1];
			if (val == 0) {
				if (p2 < len) {
					arr[p2] = val;
				}
				p2--;
				if (p2 < len) {
					arr[p2] = val;
				}
				p2--;
				p1--;
			}
			else {
				if (p2 < len) {
					arr[p2] = val;
				}
				p2--;
				p1--;
			}
		}
		return;
	}
};

// 更简洁的写法
class Solution1{
public:
	void duplicateZeros(vector<int>& A) {
		int n = A.size(), j = n + count(A.begin(), A.end(), 0);
		for (int i = n - 1; i >= 0; --i) {
			if (--j < n)
				A[j] = A[i];
			if (A[i] == 0 && --j < n)
				A[j] = 0;
		}
	}
};

int main() {
	Solution s;
	int a[] = {8,4,5,0,0,0,0,7};
	vector<int> arr(a, a+8);

	s.duplicateZeros(arr);

	return 0;
}