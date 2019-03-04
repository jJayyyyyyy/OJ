/*
https://leetcode.com/problems/queue-reconstruction-by-height/description/
同类题目 P406

题意说明:
有这么一个队伍 vector< pair<int, int> > people_origin
for( auto person : people_origin ){
	person.first 是 person 的高度 h
	person.second 是队伍中排在 person 前面且比 person 高的人的数量 k
}
现在把 people_origin 打乱了, 只给你 people, 要求我们恢复原来的 people_origin

举例:
people = [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
恢复顺序之后
people_origin = [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

以 p4 = people_origin[4] 为例, p4 的高度是 6 前面比他高的只有 p2 = [7, 0]

解题思路:
https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89345/Easy-concept-with-PythonC++Java-Solution

首先对 people 进行排序(h 降序, k 升序)
static int cmp(pair<int, int> & a, pair<int, int> & b){
	if( a.first != b.first ){
		return a.first > b.first;
	}else{
		return a.second < b.second;
	}
}

此时得到 pList = [ [7,0], [7,1], [6,1], [5,0], [5,2], [4,4] ]
然后从 index = 1 开始进行重新插入, 按照以下规则把每个人插到合适的位置
1. 如果 now.h == pre.h, 那么把 now 插到子序列的第 now.k 个位置 (这个子序列是 people_origin 中高度 h = now.h 的元素构成的子序列)
2. 如果 now.h != pre.h, 那么把 now 插到 people_origin 的第 now.k 个位置即可(因为我们已经对 people 进行排序, now 后面不会再出现比 now 高的人了)

我们发现两条规则可以合并成一条, 即
ans.insert(ans.begin() + now.second, now);
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	static int cmp(pair<int, int> & a, pair<int, int> & b){
		if( a.first != b.first ){
			return a.first > b.first;
		}else{
			return a.second < b.second;
		}
	}

	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		vector<pair<int, int>> ans;
		size_t len = people.size();
		if( len > 0 ){
			sort(people.begin(), people.end(), cmp);
			ans.push_back(people[0]);
			for( int i = 1; i < len; i++ ){
				pair<int, int> now = people[i];
				ans.insert(ans.begin() + now.second, now);
			}
		}

		return ans;
	}
};

int main() {
	Solution s;
	vector<pair<int, int>> people(6);
	people[0].first = 7;
	people[0].second = 0;
	people[1].first = 4;
	people[1].second = 4;
	people[2].first = 7;
	people[2].second = 1;
	people[3].first = 5;
	people[3].second = 0;
	people[4].first = 6;
	people[4].second = 1;
	people[5].first = 5;
	people[5].second = 2;
	s.reconstructQueue(people);

	return 0;
}
