/*
https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
A is a mountain if 
A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
现在给定一个 mountain A, 找出 A 的最大值 peak, 返回其下标
同类题目 P852
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int peakIndexInMountainArray(vector<int> & A) {
		int maxVal = -1, maxIx = -1;
		int len = A.size();
		for( int i = 0; i < len; i++ ){
			if( A[i] > maxVal ){
				maxVal = A[i];
				maxIx = i;
			}else{
				// 下降/变小 的时候即可退出
				break;
			}
		}
		return maxIx;
	}
};