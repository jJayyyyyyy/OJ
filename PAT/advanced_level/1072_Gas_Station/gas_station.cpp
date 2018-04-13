#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#define INF 0x3fffff00
#define MAXSIZE 1016
using namespace std;

int n, srcID;
int G[MAXSIZE][MAXSIZE], dist[MAXSIZE];
bool vis[MAXSIZE];

void init(){
	fill(dist, dist + MAXSIZE, INF);
	fill(vis, vis + MAXSIZE, false);
}

void Dijkstra(){
	dist[srcID] = 0;	
	// 本题没有明确的终点，因此需要计算起点到所有点的最短距离
	for( int j = 1; j <= n; ++j ){
		int minDist=INF, midV = -1;
		for( int i = 1; i <= n; ++i ){
			if( vis[i] == false && dist[i] < minDist ){
				minDist = dist[i];
				midV = i;
			}
		}
		if( midV == -1 )	return;
		vis[midV] = true;

		for( int i = 1; i <= n; ++i ){	// [1, n]
			if( vis[i] == false && G[midV][i] != INF ){
				if( dist[midV] + G[midV][i] < dist[i] ){
					dist[i] = dist[midV] + G[midV][i];
				}
			}
		}
	}
}

int str2ID(string s, int nHouse){
	int id;
	if( s[0] == 'G' ){
		id = stoi(s.substr(1)) + nHouse;
	}else{
		id = stoi(s);
	}
	return id;
}

int main(){
	fill( G[0], G[0] + MAXSIZE*MAXSIZE, INF );
	string s1, s2;
	int nHouse, nGas, m, svRange, i, j, v1, v2, len;

	cin>>nHouse>>nGas>>m>>svRange;
	n = nHouse + nGas;
	for( i = 0; i < m; ++i ){
		cin>>s1>>s2>>len;
		v1 = str2ID(s1, nHouse);
		v2 = str2ID(s2, nHouse);
		G[v1][v2] = G[v2][v1] = len;
	}

	int ansID = -1, ansDist=-1, ansTotal=INF;
	for( i = nHouse + 1; i <= n; ++i ){
		int minDist = INF, total = 0;
		srcID = i;
		init();
		Dijkstra();

		for( j = 1; j <= nHouse; ++j ){
			if( dist[j] > svRange ){
				minDist = -1;
				break;
			}else if( dist[j] < minDist ){
				minDist = dist[j];
			}
			total += dist[j];
		}
		if( minDist == -1 ){
			continue;
		}
		if( minDist > ansDist ){
			ansID = i;	// station i
			ansDist = minDist;
			ansTotal = total;
		}else if( minDist == ansDist ){
			if( total < ansTotal ){
				ansID = i;
				ansTotal = total;
			}
		}
	}
	if( ansID == -1 ){
		cout<<"No Solution\n";
	}else{
		cout<<'G'<<(ansID - nHouse)<<'\n';
		cout.setf(ios::fixed);
		cout<<setprecision(1)<<( 1.0 * ansDist )<<' ';
		cout<<setprecision(1)<<( 1.0 * ansTotal / nHouse )<<'\n';
	}
	return 0;
}