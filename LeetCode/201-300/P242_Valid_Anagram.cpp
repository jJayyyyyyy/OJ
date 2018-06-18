/*
 * https://leetcode.com/problems/valid-anagram/description/
 * 判断一个字符串 s 是否为另一个字符串 t 的 anagram , 变位词, 即同一单词, 交换字母顺序
 * 同类题目 P242
 * 
*/

// #include <iostream>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	// 1. 长度相同
	// 2. 各字符数量相同, int a[128]
	// 3. 3次循环
	bool isAnagram(string s, string t) {
		if( s.size() != t.size() ){
			return false;
		}

		int a[128] = {0};
		for( int i = 0; i < s.size(); i++ ){
			char ch = s[i];
			a[ch]++;
		}

		for( int i = 0; i < t.size(); i++ ){
			char ch = t[i];
			if( a[ch] <= 0 ){
				return false;
			}else{
				a[ch]--;
			}
		}

		for( int i = 'a'; i <= 'z'; i++ ){
			if( a[i] != 0 ){
				return false;
			}
		}
		return true;
	}
};

