/*
https://leetcode.com/problems/robot-return-to-origin/description/
给出移动序列 UDLR, 判断 Robot 能否回到原点
同类题目 P657
*/

#include <iostream>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution{
public:
	bool judgeCircle(string & moves) {
		int vertical = 0, horizontal = 0;
		for( char ch : moves ){
			if( ch == 'U' ){
				vertical++;
			}else if( ch == 'D' ){
				vertical--;
			}else if( ch == 'L' ){
				horizontal--;
			}else{
				horizontal++;
			}
		}
		return vertical == 0 && horizontal == 0;
	}
};
