/*
https://leetcode.com/problems/distribute-candies-to-people/description/?goto=old
第 rnd 轮，第 k 个人分到 n * rnd + k 个糖果，直到糖果不够为止(rnd 从 0 开始)
返回每个人分到的糖果数
同类题目 P1103


首先确定有多少轮完整的分配
然后先进行完整地分配
最后一轮，不是每个人都能领到完整的糖果，按序领糖果即可

或者暴力搜索(更直观)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> ans;
		if (num_people <= 0) {
			return ans;
		}
		ans.resize(num_people, 0);
		if (candies <= 0) {
			return ans;
		}

		int rnd = 0;
		int remainCandies = candies;
		int total;
		while (remainCandies >= 0) {
			// 差为 1 的等差数列
			int first = num_people * rnd + 1;
			int last = first + num_people - 1;
			total = (first + last) * num_people / 2;
			rnd++;
			remainCandies -= total;
		}
		remainCandies = candies;
		rnd--;

		if (rnd > 1){
			for (int i = 1; i <= num_people; i++) {
				// 差为 num_people 的等差数列
				int first = i;
				int last = first + num_people * (rnd - 1);
				int toGive = (first + last) * rnd / 2;
				ans[i - 1] = toGive;
				remainCandies -= toGive;
			}
		}
		else if (rnd == 1) {
			for (int i = 1; i <= num_people; i++) {
				int toGive = i;
				ans[i - 1] = toGive;
				remainCandies -= toGive;
			}
		}
		
		for (int i = 1; i <= num_people; i++ ) {
			int toGive = i + num_people * rnd;
			if (toGive >= remainCandies) {
				ans[i - 1] += remainCandies;
				remainCandies = 0;
				break;
			}
			else {
				ans[i - 1] += toGive;
				remainCandies -= toGive;
			}
		}

		return ans;
	}
};

class BruteForceSolution{
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> ans(num_people, 0);
		int idx = 0;
		int toGive = 1;
		while( candies > 0 ){
			if (toGive >= candies) {
				ans[idx] += candies;
				candies = 0;
				break;
			}
			else {
				ans[idx] += toGive;
				idx = (idx + 1) % num_people;

				candies -= toGive;
				toGive++;
			}
		}

		return ans;
	}
};


int main(){
	Solution s;
	s.distributeCandies(7, 4);
	s.distributeCandies(6, 4);
	s.distributeCandies(10, 4);
	s.distributeCandies(10, 3);
	s.distributeCandies(35, 4);
	s.distributeCandies(36, 4);
}
