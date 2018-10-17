/*
https://leetcode.com/problems/sort-array-by-parity-ii/description/
重新排列数组, 使得奇数位于奇数下标, 偶数位于偶数下标
同类题目 P922, P905

最简单直观的方法, 新建一个数组 ans, 然后遍历 A, 逐个将 A 中的奇数放到 ans 的奇数下标处, 将 A 中的偶数放到 ans 的偶数下标处
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int> & A) {
		int ixEven = 0, ixOdd = 1;
		int size = A.size();
		vector<int> ans(size, 0);
		for( int i = 0; i < size; i++ ){
			// 有一些 trick, 可以在一定程度上提高时间性能
			// 设定临时变量 tmp = A[i], tmp 位于寄存器
			// 1 次访存 + 1 次寄存器 < 2次访存
			int tmp = A[i];
			// 判断奇偶性, 可以用 ( (tmp & 1) == 0 ), 比取模要快
			// 一定要注意加上 (tmp & 1) 的括号, 否则由于优先级的问题, 上面的式子会变成 ( tmp & (1 == 0) ), 会报错0.0
			// 或者使用 !(tmp & 1)
			if( tmp % 2 == 0 ){
				ans[ixEven] = tmp;
				ixEven += 2;
			}else{
				ans[ixOdd] = tmp;
				ixOdd += 2;
			}
			// 当然实际情况不一定会更快, 因为编译器可能帮我们做好了这些优化
		}
		return ans;
	}
};
