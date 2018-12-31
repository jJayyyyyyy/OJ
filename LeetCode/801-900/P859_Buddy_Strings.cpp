/*
https://leetcode.com/problems/buddy-strings/description/
判断能否通过交换字符串 A 中的两个字符, 得到字符串 B
同类题目 P859
*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
	bool buddyStrings(string A, string B) {
		int charCntA[160] = {0};
		int charCntB[160] = {0};
		int len1 = A.size(), len2 = B.size();
		if( len1 != len2 ){
			return false;
		}

		for( int i = 0; i < len1; i++ ){
			charCntA[A[i]]++;
			charCntB[B[i]]++;
		}

		bool hasCntOf2 = false;
		for( int i = 'a'; i <= 'z'; i++ ){
			if( charCntA[i] != charCntB[i] ){
				return false;
			}
			if( charCntA[i] > 1 ){
				hasCntOf2 = true;
			}
		}

		bool diff1 = false, diff2 = false;
		
		for( int i = 0; i < len1; i++ ){
			if( A[i] != B[i] ){
				if( diff1 == false ){
					diff1 = true;
				}else if( diff2 == false ){
					diff2 = true;
				}else{
					return false;
				}
			}
		}
		if( diff1 == false && diff2 == false ){
			return hasCntOf2;
		}else{
			return true;
		}
	}
};
