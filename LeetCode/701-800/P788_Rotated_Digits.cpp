/*
https://leetcode.com/problems/rotated-digits/description/
这个题目的 Description 似乎是改过的, 根据我当前能够通过所有case的代码, 题目的意思是这样的
旋转num的每一位数字digit
digit是valid的条件是 2 5 6 8
num为valid的条件是, 每一位digit是valid, 或者旋转后不变 (0, 1, 8), 但num整体至少有一个valid digit
本题没啥好做的, 可略过
同类题目 P788
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int rotatedDigits(int N) {
		int cnt = 0;
		for( int i = 2; i <= N; i++ ){
			int num = i;
			int valid = false;
			while(num != 0){
				int last = num % 10;
				if( last == 2 || last == 5 || last == 6 || last == 9 ){
					valid = true;
				}else if( last == 3 || last == 4 || last == 7 ){
					valid = false;
					break;
				}else{  }
                num /= 10;
			}
			if( valid == true ){
				cnt++;
			}
		}
		return cnt;
	}
};
