/*
https://leetcode.com/problems/employee-importance/description/
树形结构，计算父节点及其子树所有结点的值的和
同类题目 P690
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

class Solution {
public:
	unordered_map<int, Employee *> table;
	int getImportance(vector<Employee*> employees, int query_id) {
		for( auto person : employees ){
			int id = person->id;
			table[id] = person;
		}
		int ans = dfs(query_id);
		return ans;
	}

	int dfs(int leader_id){
		Employee * leader = table[leader_id];
		int ans = leader->importance;
		for( int id : leader->subordinates ){
			ans += dfs(id);
		}
		return ans;
	}
};
