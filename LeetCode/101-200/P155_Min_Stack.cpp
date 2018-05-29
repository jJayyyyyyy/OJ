/*
 * https://leetcode.com/problems/min-stack/description/
 * 设计一个"最小栈" minstack, 这个堆首先是一个普通的栈, 也就是 LIFO
 * 其次, 如同 最小堆, 这个 minstack 需要在 O(1) 时间里获得栈内最小元素
 * 同类题目 P155
 * 
 * 
 * 思路: 时间复杂度要求O(1), 那么需要空间换时间, 否则遍历栈需要 O(n)
 * 维护两个普通栈s1, s2
 * s1 就是普通的栈, LIFO
 * 然后每次 s1.push(x) 的时候, 比较一下 x 与 s2.top()
 * if( s2.size() == 0 || x <= s2.top() ) {	s2.push(x);	}
 * 也就是 s2.top() 存放了当前 s1 中最小的值
*/

// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class MinStack {
public:
	stack<int> s1, s2;

	MinStack() {	
	}
	
	void push(int x) {
		s1.push(x);
		if( s2.size() == 0 || x <= s2.top() ){
			s2.push(x);
		}
	}
	
	void pop() {	
		if( s2.top() == s1.top() ){
			s2.pop();
		}
		s1.pop();
	}
	
	int top() {	
		return s1.top();
	}
	
	int getMin() {
		return s2.top();
	}
};

