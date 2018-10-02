/*
https://leetcode.com/problems/can-place-flowers/description/
给定一排坑，看能否插入 n 朵花（相邻空间不能插花）
同类题目 P605

思路:
别想太多，直接从头开始，如果相邻的坑都没有花，那就种上花，cnt++
最后返回 cnt > n 的结果即可
*/

#include <iostream>
#include <vector>
using namespace std;

// struct TreeNode{
// 	TreeNode *left, *right;
// 	int val;
// 	TreeNode(int v){
// 		val = v;
// 		left = right = NULL;
// 	}
// };

// static int x=[](){
//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     return 0;
// }();

class Solution{
public:
	bool canPlaceFlowers(vector<int> & flowerbed, int n) {
		int cnt = 0;
		int len = flowerbed.size();
		int i = 0;
		if( flowerbed[i] == 0 && flowerbed[i+1] == 0 ){
			flowerbed[i] = 1;
			cnt++;
		}
		for( i = 1; i < len-1; i++ ){
			if( flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0 ){
				flowerbed[i] = 1;
				cnt++;
			}
		}

		if( flowerbed[i-1] == 0 && flowerbed[i] == 0 ){
			flowerbed[i] = 1;
			cnt++;
		}

		return cnt >= n;
	}
};
