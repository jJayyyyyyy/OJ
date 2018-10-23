/*
https://leetcode.com/problems/to-lower-case/description/
实现 tolower()
同类题目 P709

'A' + 32 == 'a'
*/

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	string toLowerCase(string str){
		string ans = "";
		for( char ch : str ){
			if( ch >= 'A' && ch <= 'Z' ){
				ch += 32;
			}
			ans += ch;
		}
		return ans;
	}
};