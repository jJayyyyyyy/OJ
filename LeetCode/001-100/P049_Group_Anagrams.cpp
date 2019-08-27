/*
https://leetcode.com/problems/group-anagrams/description/?goto=old
hashmap
同类题目 P049
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;

		unordered_map<string, vector<string>> hashmap;
		for (string str : strs) {
			int charmap[26] = {0};
			for (char ch : str) {
				charmap[ch - 'a']++;
			}
			string key = "";
			for (char ch = 0; ch < 26; ch++) {
				key += charmap[ch];
			}
			hashmap[key].push_back(str);
		}
		unordered_map<string, vector<string>>::iterator it;
		for (it = hashmap.begin(); it != hashmap.end(); it++) {
			ans.push_back(it->second);
		}
		return ans;
	}
};


/*
相当于自己写一个 hashCode()

存在的问题:
能够快速应对短字符串
但是当字符串特别长的时候, 就算是 double 也可能会溢出
*/
class Solution2 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		const int primelist[26] = {2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
		
		unordered_map<double, vector<string>> hashmap;
		for (string str : strs) {
			double key = 1.0;
			for (char ch : str) {
				key *= primelist[ch - 'a'];
			}
			hashmap[key].push_back(str);
		}
		unordered_map<double, vector<string>>::iterator it;
		for (it = hashmap.begin(); it != hashmap.end(); it++) {
			ans.push_back(it->second);
		}
		return ans;
	}
};

int main() {
	vector<string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");

	Solution s;
	s.groupAnagrams(strs);
}