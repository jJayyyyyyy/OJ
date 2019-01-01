/*
https://leetcode.com/problems/reverse-only-letters/description/
给定字符串，仅反转其中的字母，不反转数字、下划线等字符
同类题目 P917, P905
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution{
public:
	string reverseOnlyLetters(string S){
		int i=0, j=S.size()-1;
		while( i < j ){
			while( i < S.size() && !isalpha(S[i]) ){
				i++;
			}

			while( j >= 0 && !isalpha(S[j]) ){
				j--;
			}

			if( i >= j ){
				break;
			}

			swap( S[i], S[j] );
			i++;
			j--;
		}
		return S;
	}
};