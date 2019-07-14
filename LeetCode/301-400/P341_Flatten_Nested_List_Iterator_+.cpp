/*
https://leetcode.com/problems/flatten-nested-list-iterator/description/
将嵌套的 vector 展平
如输入 [[1,1],2,[1,1]]
则将其展平为 [1, 1, 2, 1, 1]

同类题目 P341

参考思路:
https://leetcode.com/problems/flatten-nested-list-iterator/discuss/80147/Simple-Java-solution-using-a-stack-with-explanation

1. 使用递归展开, 然后将元素逐个存储到一维的 vector
2. 直接用 stack, 分层展开
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class NestedInteger {
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

// 方法1
class NestedIterator1 {
public:
	vector<int> ans_list;
	int index;

	void dfs(vector<NestedInteger> & nestedList)
	{
		if( nestedList.size() != 0 )
		{
			for( NestedInteger item : nestedList )
			{
				if( item.isInteger() )
				{
					ans_list.push_back( item.getInteger() );
				}
				else
				{
					dfs( item.getList() );
				}
			}
		}
	}

	NestedIterator(vector<NestedInteger> & nestedList)
	{
		dfs( nestedList );
		index = 0;
	}

	int next()
	{
		if( index < ans_list.size() )
		{
			return ans_list[index++];
		}
		else
		{
			return -1;
		}
	}

	bool hasNext()
	{
		return ans_list.size() != index;
	}
};


// 方法2, 动态分层展开
class NestedIterator2 {
public:
	stack<NestedInteger> stk;

	NestedIterator(vector<NestedInteger> &nestedList) {
		int size = nestedList.size();
		for( int i = size - 1; i >= 0; i-- )
		{
			stk.push(nestedList[i]);
		}
	}

	int next() {
		int item = stk.top().getInteger();
		stk.pop();
		return item;
	}

	bool hasNext() {
		while( stk.size() > 0 )
		{
			NestedInteger now = stk.top();
			if( now.isInteger() )
			{
				return true;
			}
			stk.pop();
			vector<NestedInteger> tmp_list = now.getList();
			int size = tmp_list.size();
			for( int i = size - 1; i >= 0; i-- )
			{
				stk.push( tmp_list[i] );
			}
		}
		return false;
	}
};