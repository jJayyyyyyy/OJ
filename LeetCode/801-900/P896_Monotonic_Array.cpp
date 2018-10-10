/*
https://leetcode.com/problems/monotonic-array/description/
判断数组A是否为单调非减(或非增)数组
同类题目 P896
*/


#include <iostream>
#include <vector>
using namespace std;

static int ioSpeedUp=[](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
	bool isMonotonic(vector<int>& A) {
		int size = A.size();
		if( size <= 1 ){
			return true;
		}

		bool inc=false, dec=false;
		for( int i = 1; i < size; i++ ){
			if( A[i] > A[i-1] ){
				inc = true;
			}else if( A[i] < A[i-1] ){
				dec = true;
			}

			if( inc && dec ){
				return false;
			}
		}
		return true;
		
	}
};