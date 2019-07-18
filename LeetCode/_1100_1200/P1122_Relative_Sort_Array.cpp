/*
https://leetcode.com/problems/relative-sort-array/description/?goto=old
对于 arr1，先按照 arr2 排序，得到 a1
对于那些没有在 arr2 中出现的元素，从小到大排序，得到 a2
ans = [a1, a2]
同类题目 P1122
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> relativeSortArray(vector<int> & arr1, vector<int> & arr2) {
		int cnts[1004] = {0};
		vector<int> ans(arr1.size());
		for (int num : arr1) {
			cnts[num]++;
		}

		int cur = 0;
		// 先按照 arr2 排序
		for (int num : arr2) {
			int cnt = cnts[num];
			while (cnt-- > 0) {
				// 那么把所有的 num 依次插入 ans
				ans[cur++] = num;
			}
			cnts[num] = 0;
		}
		/*
		// 可以写成 cnts[num]--，但是这样会多次访问数组，降低了效率
		for (int num : arr2) {
			while (cnts[num] > 0) {
				// 那么把所有的 num 依次插入 ans
				ans[cur++] = num;
				cnts[num]--;
			}
		}
		*/

		// 再把所有剩下的插到 ans 里面
		for (int num = 0; num <= 1000; num++) {
			int cnt = cnts[num];
			while (cnt-- > 0) {
				ans[cur++] = num;
			}
		}

		return ans;
	}
};

int main(){
	int a1[] = {2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31};
	int a2[] = {2,42,38,0,43,21};
	vector<int> arr1(a1, a1 + 20);
	vector<int> arr2(a2, a2 + 6);

	Solution s;
	vector<int> ans = s.relativeSortArray(arr1, arr2);
	for (int num : ans) {
		cout << num << ' ';
	}
	cout << '\n';
	return 0;
}

/*
int a1[] = {2,3,1,3,2,4,6,7,9,2,19};
int a2[] = {2,1,4,3,9,6};
vector<int> arr1(a1, a1 + 11);
vector<int> arr2(a2, a2 + 6);



int a1[] = {2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31}
int a2[] = {2,42,38,0,43,21}
vector<int> arr1(a1, a1 + 20);
vector<int> arr2(a2, a2 + 6);


*/