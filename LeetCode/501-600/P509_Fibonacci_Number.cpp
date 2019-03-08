/*
https://leetcode.com/problems/fibonacci-number/description/
同类题目: P509

求 Fibonacci 数
*/

#include <iostream>
using namespace std;

class Solution
{
public:
	long long arr[32];
	int fib(int N) {
		arr[0] = 0;
		arr[1] = 1;
		for( int i = 2; i <= N; i++ )
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[N];
	}
};
