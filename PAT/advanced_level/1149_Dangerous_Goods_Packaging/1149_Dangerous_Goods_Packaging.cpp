#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, id1, id2;
	cin>>n>>m;
	unordered_map< int, unordered_set<int> > um;
	for( int i = 0; i < n; i++ ){
		cin>>id1>>id2;
		um[id1].insert(id2);
		um[id2].insert(id1);
	}

	int k, id;
	bool ans=false;
	for( int i = 0; i < m; i++ ){
		cin>>k;
		unordered_set<int> goods;
		// vector<int> goods;
		for( int j = 0; j < k; j++ ){
			cin>>id;
			// goods.push_back(id);
			goods.insert(id);
		}
		for( int id1 : goods ){
			if( um.find(id1) != um.end() ){
				for( int id2 : um[id1] ){
					if( goods.find(id2) != goods.end() ){
						ans = true;
						break;
					}
				}
			}
		}
		
		// 这样遍历会超时
		// for( int x = 0; x < k-1; x++ ){
		// 	for( int y = x+1; y < k ; y++ ){
		// 		id1 = goods[x];
		// 		id2 = goods[y];
		// 		if( um.find(id1) != um.end() && um[id1].find(id2) != um[id1].end() ){
		// 			ans = true;
		// 			break;
		// 		}
		// 	}
		// }

		if( ans == true ){
			cout<<"No\n";
		}else{
			cout<<"Yes\n";
		}
		ans = false;
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

