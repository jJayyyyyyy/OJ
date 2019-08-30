/*
https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/?goto=old

同类题目 P1170

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int getFreq(string s) {
		int cnt[32] = {0};
		for (char ch : s) {
			cnt[ch - 'a']++;
		}

		int freq = 0;
		for (int i = 0; i < 26; i++) {
			freq = cnt[i];
			if (freq != 0) {
				break;
			}
		}
		return freq;
	}

	/*
	思路1
	先统计 words 的频度列表 freqOfWords ，然后对其进行排序
	接着逐个计算 query 的频度 freq ，利用二分法查找在 freqOfWords 中, freq 的后面还有多少个数
	*/
	vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
		vector<int> freqOfWords;
		for (string word : words) {
			int freq = getFreq(word);
			freqOfWords.push_back(freq);
		}
		sort(freqOfWords.begin(), freqOfWords.end());

		vector<int> ans;
		for (string query : queries) {
			int freq = getFreq(query);
			vector<int>::iterator pos = upper_bound(freqOfWords.begin(), freqOfWords.end(), freq);
			int num = freqOfWords.end() - pos;
			ans.push_back(num);
		}
		return ans;
	}
};
