/*
https://leetcode.com/problems/implement-queue-using-stacks/solution/
用栈实现队列

同类题目 P232, P225
方法: 设队列为 d, 建立两个栈 s1, s2, 两次 LIFO 就变成了 FIFO
*/

#include <iostream>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class MyQueue {
	stack<int> in, out;
public:
	/** Initialize your data structure here. */
	MyQueue() {
	}
	
	/** Push element x to the back of queue. */
	void push(int x) {
		in.push(x);
	}
	
	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int pk = peek();
		out.pop();
		return pk;
	}
	
	/** Get the front element. */
	int peek() {
		if( out.empty() ){
			while( in.size() != 0 ){
				int x = in.top();
				out.push(x);
				in.pop();
			}
		}
		return out.top();
	}
	
	/** Returns whether the queue is empty. */
	bool empty() {
		return in.empty() && out.empty();
	}
};

