/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
给定一个字符串 s 和一个 非空串 p，寻找 s 中所有的 p 的变形串（字符种类和数量相同，顺序不同）
同类题目 P438, 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();


// struct TreeNode {
// 	int val;
// 	TreeNode *left, *right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL){}
// };


class Solution{
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		int len1 = s.size();
		int len2 = p.size();

		if( len1 > len2 ){
			vector<int> charCnt(128, 0);
			for( char ch : p ){
				charCnt[ch]++;
			}

			for( int i = 0; i <= len1 - len2; i++ ){
				bool found = true;
				vector<int> tmpCharCnt = charCnt;
				for( int j = 0; j < len2; j++ ){
					char ch = s[i + j];
					tmpCharCnt[ch]--;
					if( tmpCharCnt[ch] < 0 ){
						found = false;
						break;
					}
				}

				if( found == true ){
					for( int k = 'a'; k <= 'z'; k++ ){
						if( tmpCharCnt[k] != 0 ){
							found = false;
							break;
						}
					}
				}
				
				if( found == true ){
					ans.push_back(i);
				}
			}
		}
		
		return ans;
	}
};


int main(){
	Solution s;
	
	vector<int> ans;

	ans = s.findAnagrams("cbaebabacd", "abc");
	for( int i : ans ){
		cout<<i<<' ';
	}
	cout<<'\n';
	
	ans = s.findAnagrams("abab", "ab");
	for( int i : ans ){
		cout<<i<<' ';
	}
	cout<<'\n';

	return 0;
}