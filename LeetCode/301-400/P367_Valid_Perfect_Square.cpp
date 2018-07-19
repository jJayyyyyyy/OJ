/*
https://leetcode.com/problems/valid-perfect-square/description/
判断一个数是否为完全平方数，本题不能使用库函数sqrt()
同类题目 P367

参考: https://leetcode.com/problems/valid-perfect-square/discuss/83874/A-square-number-is-1+3+5+7+...-JAVA-code
方法1. 如果num是完全平方数，那么 num = 1 + 3 + 5 + 7 + ...
方法2. 在[1, num) 上进行二分查找，每找一个数mid，就用 mid * mid == num 进行判断。注意 mid 的类型是 long long, 否则 mid * mid 可能溢出

*/

#include <iostream>
using namespace std;

class Solution1 {
public:
	bool isPerfectSquare(int num) {
		if( num <= 0 ){
			return false;
		}

		int i = 1;
		while( num > 0 ){
			num -= i;
			i += 2;
		}
		return num == 0;
	}
};

class Solution2{
public:
	bool isPerfectSquare(int num){
		if( num <= 0 ){
			return false;
		}

		int left = 1, right = num;
		while( left <= right ){
			long long mid = (left + right) / 2;
			long long res = mid * mid;
			if( res == num ){
				return true;
			}else if( res < num ){
				left = (int) mid + 1;
			}else{
				right = (int) mid - 1;
			}
		}
		return false;
	}
};

