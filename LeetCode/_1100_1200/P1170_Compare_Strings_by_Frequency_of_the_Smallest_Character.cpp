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

	/*
	思路2
	不需要每次都去二分查找
	由于 1 <= queries[i].length, words[i].length <= 10
	也就是说最多有 10 种频度
	我们可以直接把频度保存在 hashmap 里面
	然后
	*/
	vector<int> numSmallerByFrequency_faster(vector<string>& queries, vector<string>& words) {
		vector<int> freqOfWords(16, 0);
		for (string word : words) {
			int freq = getFreq(word);
			freqOfWords[freq]++;
		}

		for (int i = 9; i >= 0; i--) {
			freqOfWords[i] += freqOfWords[i + 1];
		}

		vector<int> ans;
		for (string query : queries) {
			int freq = getFreq(query);
			int num = freqOfWords[freq + 1];
			ans.push_back(num);
		}
		return ans;
	}
};
