#include <iostream>
#include <algorithm>
#define MAX 1004
#define START 1
using namespace std;

int n, ix=START;
int nodeList[MAX] = {0};		// [1, n]
int CBT[MAX] = {0};				// [1, n]

void inOrder(int root){
	if( root <= n ){
		inOrder( root*2 );		// lchild
		CBT[root] = nodeList[ix++];
		inOrder( root*2 + 1 );	// rchild
	}
}

int main(){
	int i, root=1;
	cin>>n;

	for( i=1; i<=n; i++ ){
		cin>>nodeList[i];
	}
	sort( nodeList + 1, nodeList + 1 + n );
	inOrder(root);

	cout<<CBT[1];
	for( i=2; i<=n; i++ ){
		cout<<' '<<CBT[i];
	}
	return 0;
}