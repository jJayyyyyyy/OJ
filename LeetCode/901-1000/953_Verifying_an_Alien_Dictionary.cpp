/*
https://leetcode.com/problems/verifying-an-alien-dictionary/description/
定义一个新的字典序，要求判断一组字符串是否为升序排列
同类题目 P953
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
	bool isAlienSorted(vector<string> & words, string order) {
		int dict[160];
		int len = order.size();
		for( int i = 0; i < len; i++ ){
			char ch = order[i];
			dict[ch] = i;
		}

		bool flag = true;
		len = words.size();
		for( int i = 1; i < len; i++ ){
			string s1 = words[i-1];
			string s2 = words[i];
			int len1 = s1.size();
			int len2 = s2.size();
			int len3 = len1;
			if( len1 > len2 ){
				len3 = len2;
			}
			bool innerFlag = true;
			for( int j = 0; j < len3; j++ ){
				char ch1 = s1[j];
				char ch2 = s2[j];
				int alien1 = dict[ch1];
				int alien2 = dict[ch2];
				if( alien1 == alien2 ){
					continue;
				}else{
					flag = alien1 < alien2;
					innerFlag = false;
					break;
				}
			}
			if( innerFlag == true && len1 > len2 ){
				flag = false;
			}

			if( flag == false ){
				break;
			}
		}
		return flag;
	}
};

int main(){
	Solution s;
	vector<string> words;
	string order;

	words.push_back("kuvp");
	words.push_back("q");
	order = "ngxlkthsjuoqcpavbfdermiywz";
	s.isAlienSorted(words, order);

	// words.push_back("hello");
	// words.push_back("leetcode");
	// order = "hlabcdefgijkmnopqrstuvwxyz";
	// s.isAlienSorted(words, order);

	return 0;
}
