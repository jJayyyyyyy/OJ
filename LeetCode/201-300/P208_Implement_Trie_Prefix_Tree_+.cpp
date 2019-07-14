/*
https://leetcode.com/problems/implement-trie-prefix-tree/description/
实现 Trie (读作 try)
同类题目 P208

参考思路
http://zxi.mytechroad.com/blog/data-structure/leetcode-208-implement-trie-prefix-tree/
https://leetcode.com/problems/implement-trie-prefix-tree/solution/
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TrieNode {
	bool isWord;
	unordered_map<char, TrieNode *> children;

	TrieNode(){
		isWord = false;
	}
};

class Trie {
public:
	TrieNode * root;

	TrieNode * find(const string & prefix){
		TrieNode * p = root;
		for( char ch : prefix ) {
			if( p->children.find(ch) == p->children.end() ){
				p = NULL;
				break;
			}
			p = p->children[ch];
		}
		return p;
	}

	/** Initialize your data structure here. */
	Trie(){
		root = new TrieNode();
	}
	
	/** Inserts a word into the trie. */
	void insert(const string & word) {
		TrieNode * p = root;
		for( char ch : word ){
			if ( p->children.find(ch) == p->children.end() ){
				p->children[ch] = new TrieNode();
			}
			p = p->children[ch];
		}
		p->isWord = true;
	}
	
	/** Returns if the word is in the trie. */
	bool search(const string & word){
		TrieNode * p = find(word);
		if( p != NULL ){
			if( p->isWord == true ){
				return true;
			}
		}
		return false;
	}
	
	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(const string & prefix){
		TrieNode * p = find(prefix);
		if( p != NULL ){
			return true;
		}else{
			return false;
		}
	}
};
