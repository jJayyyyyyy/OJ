#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXSIZE 1004
using namespace std;

int nodeList[MAXSIZE];
vector<int> ansList;
int m, n;

bool isMinHeap(int root){
	for( int i = 1; i <= n/2; i++ ){
		int lchild = i * 2;
		int rchild = i * 2 + 1;
		if( lchild <= n ){
			if( nodeList[i] > nodeList[lchild] ){
				return false;
			}
		}
		
		if( rchild <= n ){
			if( nodeList[i] > nodeList[rchild] ){
				return false;
			}
		}
	}
	return true;
}

bool isMaxHeap(int root){
	for( int i = 1; i <= n/2; i++ ){
		int lchild = i * 2;
		int rchild = i * 2 + 1;
		if( lchild <= n ){
			if( nodeList[i] < nodeList[lchild] ){
				return false;
			}
		}
		
		if( rchild <= n ){
			if( nodeList[i] < nodeList[rchild] ){
				return false;
			}
		}
	}
	return true;
}

void postTrav(int root){
	if( root <= n ){
		postTrav(root * 2);
		postTrav(root * 2 + 1);
		ansList.push_back(nodeList[root]);
	}
}

void printAns(){
	for( int i = 0; i < ansList.size(); i++ ){
		if( i != 0 ){
			cout<<' ';
		}
		cout<<ansList[i];
	}
	ansList.clear();
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>m>>n;

	for( int i = 0; i < m; i++ ){
		for( int j = 1; j <= n; j++ ){
			cin>>nodeList[j];
		}
		if( nodeList[1] < nodeList[2] ){
			if( isMinHeap(1) == true ){
				cout<<"Min Heap\n";
			}else{
				cout<<"Not Heap\n";
			}
		}else{
			if( isMaxHeap(1) == true ){
				cout<<"Max Heap\n";
			}else{
				cout<<"Not Heap\n";
			}
		}
		postTrav(1);
		printAns();
	}
	return 0;
}
