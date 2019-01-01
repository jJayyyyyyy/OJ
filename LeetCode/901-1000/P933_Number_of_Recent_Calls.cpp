/*
https://leetcode.com/problems/number-of-recent-calls/description/
给定一个输入序列, 每个元素对应一个时间(升序) t,
设当前元素的时间为 tnow, 统计在 [tnow-3000, t] 的时间段内有多少个元素
同类题目 P933

思路
利用队列, 每次加入新元素后, 根据 tnow, 把时间小于 tnow -3000 的元素全部pop
由于输入序列的时间都是升序的, 所以刚好可以结合队列的特性,
while( qCall.front() < tnow - 3000 ){
	qCall.pop();
}
把过期的元素全部剔除
*/

#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
private:
	queue<int> qCall;
public:
	RecentCounter() {
		
	}

	int ping(int tnow){
		qCall.push(tnow);
		while( qCall.front() < tnow - 3000 ){
			qCall.pop();
		}
		return qCall.size();
	}
};
