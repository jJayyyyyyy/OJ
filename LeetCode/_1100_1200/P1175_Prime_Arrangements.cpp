/*
https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?goto=old
素数相关
一个长度为 n 的数组，包含了 1~n 的所有数字，且数组下标从1开始
现在对数组进行全排列，但是要求素数的下标必须也是素数
问有多少种这样的排列
同类题目 P1175

筛表法
https://github.com/jJayyyyyyy/OJ/blob/master/notes/Question1.md

设 1~n 中有 x 个素数, y 个非素数
n = x + y
ans = x! * y! mod (10^9 + 7)
*/

#include <iostream>
using namespace std;

class Solution {
private:
	#define MAXSIZE 101
	bool primelist[MAXSIZE];
public:
	int numPrimeArrangements(int n) {
		init();
		int x = cnt_prime(n);
		unsigned long long fx = factorial(x);
		int y = n - x;
		unsigned long long fy = factorial(y);
		int ans = fx * fy % 1000000007;
		return ans;
	}

	void init() {
		// 初始化素数表
		primelist[0] = false;
		primelist[1] = false;
		primelist[2] = true;
		for (int i = 3; i < MAXSIZE; i+= 2) {
			primelist[i] = true;
			primelist[i + 1] = false;
		}
		int upper = (int) sqrt(MAXSIZE);
		for (int i = 3; i < upper; i += 2) {
			if (primelist[i] == true) {
				for (int j = i + i; j < MAXSIZE; j += i) {
					primelist[j] = false;
				}
			}
		}
	}

	// 统计 1~n 有多少个素数
	int cnt_prime(int n) {
		int cnt = 0;
		for (int i = 2; i <= n; i++) {
			if (primelist[i] == true) {
				cnt++;
			}
		}
		return cnt;
	}

	// 阶乘
	unsigned long long  factorial(int x) {
		unsigned long long  fx = 1;
		for (int i = 1; i <= x; i++) {
			fx = fx * i % 1000000007;
		}
		return fx;
	}
};

int main() {
	Solution s;
	s.numPrimeArrangements(100);
	return 0;
}