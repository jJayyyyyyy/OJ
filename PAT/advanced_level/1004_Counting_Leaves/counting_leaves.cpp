#include <iostream>
#include <vector>
#include <queue>
#define MAXSIZE 104
using namespace std;

struct Person
{
	int id;
	vector<int> children;
};

vector<Person> family(MAXSIZE);

void BFS()
{
	queue<int> q;
	int root_id = 1;
	q.push(root_id);

	vector<int> ans;
	while( q.size() != 0 )
	{
		int len = q.size();
		int cnt_leaf = 0;
		for( int i = 0; i < len; i++ )
		{
			int parent_id = q.front();
			q.pop();
			vector<int> children = family[parent_id].children;
			if( children.size() == 0 )
			{
				cnt_leaf++;
			}
			else
			{
				for( int child_id : children )
				{
					q.push(child_id);
				}
			}
		}
		ans.push_back(cnt_leaf);
	}

	int len = ans.size();
	cout << ans[0];
	for( int i = 1; i < len; i++ )
	{
		cout << ' ' << ans[i];
	}
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int parent_id, cnt;
	for( int i = 0; i < m; i++ )
	{
		cin >> parent_id >> cnt;
		vector<int> children(cnt);
		for( int j = 0; j < cnt ; j++ )
		{
			cin >> children[j];
		}
		family[parent_id].children = children;
	}
	BFS();

	return 0;
}
