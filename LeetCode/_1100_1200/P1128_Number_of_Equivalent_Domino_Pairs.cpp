/*
https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?goto=old

同类题目 P1208

基本思路
先对每一组坐标排序，[2,1] 变成 [1,2]
然后放到 map 里面，key是坐标，值是出现的次数
最后，那些次数大于1的就是 equivalent dominoes
最后统计

改进思路:
https://leetcode.com/problems/number-of-equivalent-domino-pairs/discuss/340022/JavaC++Python-Easy-and-Concise
1. 不需要排序，由于坐标只有两位，可以组成一个两位数，把小的放在十位，大的放在个位，
   这样，equivalent dominoes 对应了唯一的一个两位数

2. 不需要map，只需要一个 int bitmap[100] 即可

3. 统计的时候，比如 bitmap[index] 的值为 n，也就是说有 n 对坐标映射到了一起
   这时，有效的 pair = C(2,n), 即2在上3在下的排列数
   C(2,n) = (n) * (n - 1) / 2
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		int bitmap[100] = {0};
		for (const vector<int> & item : dominoes) {
			int a = item[0];
			int b = item[1];
			if (a > b){
				int c = a;
				a = b;
				b = c;
			}
			int index = a * 10 + b;
			bitmap[index]++;
		}
		int ans = 0;
		for (int i = 0; i < 100; i++) {
			int cnt = bitmap[i];
			if (cnt > 1) {
				ans += (cnt) * (cnt - 1) / 2;
			}
		}
		return ans;
	}
};