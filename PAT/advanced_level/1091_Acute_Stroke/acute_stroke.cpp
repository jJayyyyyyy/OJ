#include <iostream>
#include <queue>
#define MAXZ 64
#define MAXX 1290
#define MAXY 130
using namespace std;

int sizeZ, sizeX, sizeY, TH;
bool pixel[MAXZ][MAXX][MAXY] = {false};
bool vis[MAXZ][MAXX][MAXY] = {false};

struct Node{
	int z, x, y;
	Node(int _z, int _x, int _y): z(_z), x(_x), y(_y){}
};

bool judge(int z, int x, int y){
	if( z >= sizeZ || z < 0 || x >= sizeX || x < 0 || y >= sizeY || y < 0 ){
		return false;
	}else if( pixel[z][x][y] == false || vis[z][x][y] == true ){
		return false;
	}else{
		return true;
	}
}

int BFS(int z, int x, int y){
	int incZ[6] = {1, -1, 0, 0, 0, 0};
	int incX[6] = {0, 0, 1, -1, 0, 0};
	int incY[6] = {0, 0, 0, 0, 1, -1};
	int cnt = 0;
	queue<Node> q;
	Node node(z, x, y);
	q.push(node);
	vis[z][x][y] = true;

	while( q.size() ){
		Node now = q.front();
		q.pop();
		++cnt;
		for( int i = 0; i < 6; ++i ){
			int nextZ = now.z + incZ[i];
			int nextX = now.x + incX[i];
			int nextY = now.y + incY[i];
			if( judge(nextZ, nextX, nextY) ){
				Node next(nextZ, nextX, nextY);
				q.push(next);
				vis[nextZ][nextX][nextY] = true;
			}
		}
	}
	if( cnt >= TH ){
		return cnt;
	}else{
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>sizeX>>sizeY>>sizeZ>>TH;
	for( int z = 0; z < sizeZ; ++z ){
		for( int x = 0; x < sizeX; ++x ){
			for( int y = 0; y < sizeY; ++y ){
				cin>>pixel[z][x][y];
			}
		}
	}
	int totalVol = 0;
	for( int z = 0; z < sizeZ; ++z ){
		for( int x = 0; x < sizeX; ++x ){
			for( int y = 0; y < sizeY; ++y ){
				if( pixel[z][x][y] == true && vis[z][x][y] == false ){
					totalVol += BFS(z, x, y);
				}
			}
		}
	}
	cout<<totalVol<<'\n';
	return 0;
}