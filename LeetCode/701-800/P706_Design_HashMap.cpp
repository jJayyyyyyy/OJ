/*
https://leetcode.com/problems/design-hashset/description/
实现 hashSet
同类题目 P706, P705

TODO:
学习 STL 中 unordered_set 的实现
/usr/include/c++/4.8.4/bits/unordered_set.h
*/

#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
public:
	vector<bool> hasharray;
	int SIZE;

	/** Initialize your data structure here. */
	MyHashSet() {
		hasharray = vector<bool>(1000007, false);
		SIZE = 1000000;
	}
	
	void add(int key) {
		if( key >= 0 && key <= SIZE ){
			hasharray[key] = true;
		}
	}
	
	void remove(int key) {
		if( key >= 0 && key <= SIZE ){
			hasharray[key] = false;
		}
	}
	
	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		if( key >= 0 && key <= SIZE ){
			return hasharray[key];
		}
	}
};
