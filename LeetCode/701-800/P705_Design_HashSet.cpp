/*
https://leetcode.com/problems/design-hashmap/description/
实现 hashMap
同类题目 P706, P705

TODO:
学习 STL 中 unordered_map 的实现
/usr/include/c++/4.8.4/bits/unordered_map.h
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> hasharray;

	MyHashMap(){
		hasharray = vector<int>(1000004, -1);
	}

	void put(int key, int value){
		if( key >= 0 && key <= 1000000 ){
			hasharray[key] = value;
		}
	}

	int get(int key){
		if( key >= 0 && key <= 1000000 ){
			return hasharray[key];
		}
		return -1;
	}

	void remove(int key){
		if( key >= 0 && key <= 1000000 ){
			hasharray[key] = -1;
		}
	}
};
