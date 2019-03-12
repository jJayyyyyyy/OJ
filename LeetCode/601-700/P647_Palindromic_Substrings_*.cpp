/*
https://leetcode.com/problems/palindromic-substrings/description/
判断一个字符串中有多少个回文子串(只要起始下标/终止下标不一样, 就算新的子串)
同类题目 P647

思路1:
https://leetcode.com/problems/palindromic-substrings/solution/
遍历子串中点。选定中点后, 向两边延伸, 判断延伸后的子串是否为回文串
时间复杂度 O(N^2)


*/

#include <iostream>
#include <vector>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// 遍历子串中点。选定中点后, 向两边延伸, 判断延伸后的子串是否为回文串
class Solution {
public:
	int countSubstrings(string s) {
		int len = s.size();
		int cntCenter = len * 2 - 1;
		int ans = 0;
		for( int center = 0; center <= cntCenter; center++ ){
			int left = center / 2;
			int right = left + center % 2;
			while( left >= 0 && right < len && s[left] == s[right] ){
				ans++;
				left--;
				right++;
			}
		}
		return ans;
	}
};