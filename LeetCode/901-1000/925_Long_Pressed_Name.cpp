/*
https://leetcode.com/problems/long-pressed-name/description/
判断字符串name是不是字符串typed的子串(可以是不连续子串, 但是字符相对顺序必须相同)
同类题目 P925
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		name.push_back('#');
		typed.push_back('#');
		vector<string> n, t;
		int len1 = name.size();
		int len2 = typed.size();
		int pre = 0;
		for( int i = 1; i < len1; i++ ){
			if( name[i-1] != name[i] ){
				int len = i - pre;
				n.push_back(name.substr(pre, len));
				pre = i;
			}
		}

		pre = 0;
		for( int i = 1; i < len2; i++ ){
			if( typed[i-1] != typed[i] ){
				int len = i - pre;
				t.push_back(typed.substr(pre, len));
				pre = i;
			}
		}

		len1 = n.size();
		len2 = t.size();
		if( len1 != len2 ){
			return false;
		}
		if( len1 == len2 ){
			bool ans = true;
			for( int i = 0; i < len1; i++ ){
				if( n[i][0] != t[i][0] ){
					ans = false;
					break;
				}else{
					if( n[i].size() > t[i].size() ){
						ans = false;
						break;
					}
				}
			}
			return ans;
		}
	}
};

class Solution2 {
public:
	bool isLongPressedName(string name, string typed) {
		int len1 = name.size();
		int len2 = typed.size();
		int i = 0, j = 0;
		while( i < len1 && j < len2 ){
			if( name[i] == typed[j] ){
				i++;
				j++;
			}else{
				j++;
			}
		}
		return i == len1;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Solution s;
	string name = "alex";
	string typed = "aaleex";
	s.isLongPressedName(name, typed);

	return 0;
}