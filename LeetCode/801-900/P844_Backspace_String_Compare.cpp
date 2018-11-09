/*
https://leetcode.com/problems/backspace-string-compare/description/
输入字符串如
S = "ab#c", T = "ad#c"
其中 '#' 表示 backspace, 退格(删除)
判断 S , T 最后形成的字符串是否相同
同类题目 P844

注意退格到 0 再退格的时候, 下标不会变成负数
*/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool backspaceCompare(string S, string T){
		string tmpS="", tmpT="";
		for( char ch : S ){
			if( ch == '#' ){
				if( tmpS.size() > 0 ){
					tmpS.pop_back();
				}
			}else{
				tmpS.push_back(ch);
			}
		}

		for( char ch : T ){
			if( ch == '#' ){
				if( tmpT.size() > 0 ){
					tmpT.pop_back();
				}
			}else{
				tmpT.push_back(ch);
			}
		}

		return tmpS == tmpT;
	}
};