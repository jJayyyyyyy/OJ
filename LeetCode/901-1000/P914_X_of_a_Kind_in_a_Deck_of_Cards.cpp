/*
https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/

同类题目 P914

参考思路
先统计数字出现次数，然后求各个数字出现次数的最大公因数
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		int cnt[10004] = {0};
		for ( int card : deck) {
			cnt[card]++;
		}

		int gcd = -1;
		for (int i = 0; i < 10000; ++i){
			if (cnt[i] > 0) {
				if (gcd == -1) {
					gcd = cnt[i];
				}
				else {
					gcd = get_gcd(gcd, cnt[i]);
				}
			}
		}
		return gcd >= 2;
	}

	int get_gcd (int a, int b) {
		return b == 0 ? a : get_gcd(b, a % b);
	}
};