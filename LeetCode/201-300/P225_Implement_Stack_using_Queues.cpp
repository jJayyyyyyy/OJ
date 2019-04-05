/*
https://leetcode.com/problems/implement-stack-using-queues/description/
用 队列 实现 栈

同类题目
P225, P232

参考思路
*/

#include <iostream>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
public:
	queue<int> q1, q2;
	/** Initialize your data structure here. */
	MyStack() {
		
	}
	
	/** Push element x onto stack. */
	void push(int x) {
		q1.push(x);
	}
	
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int val = -1;
		if( q1.size() > 0 ){
			while( q1.size() > 1 ){
				val = q1.front();
				q1.pop();
				q2.push(val);
			}
			val = q1.front();
			q1.pop();
			swap(q1, q2);
		}

		return val;
	}
	
	/** Get the top element. */
	int top() {
		int val = -1;
		while( q1.size() > 0 ){
			val = q1.front();
			q1.pop();
			q2.push(val);
		}
		swap(q1, q2);
		return val;
	}
	
	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.size() == 0;
	}
};
