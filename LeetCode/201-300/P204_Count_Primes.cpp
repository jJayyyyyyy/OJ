/*
 * https://leetcode.com/problems/count-primes/description/
 * 数素数
 * 同类题目 P204
 * 
 * 筛表法, 简化
 * 原来要循环 3 遍, 现在只要走 1 遍
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
	int countPrimes(int n) {
		if( n <= 2 ){
			return 0;
		}

		vector<bool> primeList(n, true);
		int cnt = 1;

		int upper = (int) sqrt(n);
		for( int i = 3; i < n; i += 2 ){
			if( primeList[i] == true ){
				cnt++;
				if( i <= upper ){
					for( int j = i + i; j < n; j += i ){
						primeList [j] = false;
					}
				}
			}
		}

		return cnt;
	}
};
