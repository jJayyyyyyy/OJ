#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/* 30 ms, 1200 KB */
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int id1, id2;
	unordered_map<int, vector<int> > incompatible_map;
	for( int i = 0; i < n; i++ )
	{
		cin >> id1 >> id2;
		incompatible_map[id1].push_back(id2);
		incompatible_map[id2].push_back(id1);
	}

	for( int i = 0; i < m; i++ )
	{
		int k;
		cin >> k;
		vector<int> line;
		for( int j = 0; j < k; j++ )
		{
			cin >> id1;
			line.push_back(id1);
		}

		for( int i = 0; i < k; i++ )
		{
			int id1 = line[i];
			if( incompatible_map.find(id1) != incompatible_map.end() )
			{
				vector<int> incompatible_vec = incompatible_map[id1];
				// incompatible_vec == {006, 005, 003}
				for( int j = i + 1; j < k; j++ )
				{
					int id2 = line[j];
					for( int id3 : incompatible_vec )
					{
						if( id2 == id3 )
						{
							cout << "No\n";
							goto nextloop;
						}
					}
				}
			}
		}
		cout << "Yes\n";
	nextloop:
		continue;
	}

	return 0;
}

/*
6 3
20001 20002
20003 20004
20005 20006
20003 20001
20005 20004
20004 20006
4 00001 20004 00002 20003
5 98823 20002 20003 20006 10010
3 12345 67890 23333

*/

/*
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

// 50 ms, 2200 KB
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	unordered_map<int, unordered_set<int> > incompatible_map;
	int id1, id2;
	for( int i = 0; i < n; i++ )
	{
		cin >> id1 >> id2;
		incompatible_map[id1].insert(id2);
		incompatible_map[id2].insert(id1);
	}

	for( int i = 0; i < m; i++ )
	{
		unordered_set<int> line;
		int k;
		cin >> k;
		for( int j = 0; j < k; j++ )
		{
			cin >> id1;
			line.insert(id1);
		}

		for( int id1 : line )
		{
			if( incompatible_map.find(id1) != incompatible_map.end() )
			{
				unordered_set<int> incompatible_set = incompatible_map[id1];
				for( int id2 : incompatible_set )
				{
					if( line.find(id2) != line.end() )
					{
						cout << "No\n";
						goto nextloop;
					}
				}
			}
		}
		cout << "Yes\n";
	nextloop:
		continue;
	}

	return 0;
}
*/