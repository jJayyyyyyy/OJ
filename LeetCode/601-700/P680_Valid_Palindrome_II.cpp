/*
https://leetcode.com/problems/valid-palindrome-ii/description/
判断一个字符串是否为对称的字符串
本题最多允许一个非对称字符, 如 abca 在本题条件下是合法的对称字符串
同类题目 P680
*/

#include <iostream>
#include <string>
using namespace std;


/*
参考思路
https://leetcode.com/problems/valid-palindrome-ii/solution/
*/
class Solution {
public:
	bool subStrValidPalid(string & s, int i, int j){
		while( i < j ){
			if( s[i] != s[j] ){
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

	bool validPalindrome(string s) {
		int len = s.size();

		if( len <= 1 ){
			return true;
		}

		int halflen = len / 2;
		// 由于最多只有一个错误字符
		for( int i = 0; i < halflen; i++ ){
			if( s[i] != s[len-1-i] ){
				int j = len - 1 - i;
				return ( subStrValidPalid(s, i+1, j) || subStrValidPalid(s, i, j-1) );
			}
		}

		return true;
	}
};

// 以下解法不能通过所有测试
// 注意特例 tmpHead == tail && head == tmpTail
// 如 string s = "aguokepatgbnvfq mgml[c] upuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuc [u]lmgm qfvnbgtapekouga";
/*
class FalseSolution {
public:
	bool validPalindrome(string s) {
		int len = s.size();

		if( len <= 1 ){
			return true;
		}

		int halflen = len / 2;
		char head = s[0], tail = s[len-1];
		bool hasDel = false;
		int i = 0, j = len - 1;
		while( i < j ){
			head = s[i];
			tail = s[j];
			if( head != tail ){
				if( hasDel == false ){
					hasDel = true;
					int tmpHead = s[i + 1];
					int tmpTail = s[j - 1];
					if( tmpHead == tail ){
						i++;
					}else if( head == tmpTail ){
						j--;
					}else{
						return false;
					}
				}else{
					return false;
				}
			}
			i++;
			j--;
		}
		return true;
	}
};
*/