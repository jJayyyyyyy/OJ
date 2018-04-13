#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n, col, row, color;
	map<int, int> colorMap;
	map<int, int>::iterator it;
	
	cin>>m>>n;
	for(row=0; row<n; row++){
		for(col=0; col<m; col++){
			cin>>color;
			if( colorMap.find(color)!=colorMap.end() ){
				colorMap[color]++;
			}else{
				colorMap[color] = 1;
			}
		}
	}

	int maxCnt=m*n/2;
	for( it=colorMap.begin(); it!=colorMap.end(); it++){
		if( it->second >maxCnt ){
			cout<<it->first;
			break;
		}
	}

	return 0;
}
