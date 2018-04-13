#include <iostream>
#include <queue>
#include <algorithm>
#define MAXSIZE 104
using namespace std;

struct Node{
	int lchild=-1, rchild=-1;
	int val=-1;
};

Node nodeList[MAXSIZE];
int incList[MAXSIZE];
int ix=0, isFirst=1;

void inOrder(int root){
	if( root != -1 ){
		inOrder( nodeList[root].lchild );
		nodeList[root].val = incList[ix++];
		inOrder( nodeList[root].rchild );
	}
}

void visit(int root){
	if( root != -1 ){
		if( isFirst ){
			cout<<nodeList[root].val;
			isFirst = 0;
		}else{
			cout<<' '<<nodeList[root].val;
		}
	}
}

void levelOrder(int root){
	if( root != -1 ){
		queue<int> q;
		q.push(root);
		while( q.size() > 0 ){
			int node = q.front();
			visit(node);
			q.pop();
			if( nodeList[node].lchild != -1 ){
				q.push(nodeList[node].lchild);
			}
			if( nodeList[node].rchild != -1 ){
				q.push(nodeList[node].rchild);
			}
		}
	}
}

int main(){
	int n, i, root=0;
	cin>>n;
	for( i = 0; i < n; ++i ){
		cin>>nodeList[i].lchild>>nodeList[i].rchild;
	}
	for( i = 0; i < n; ++i ){
		cin>>incList[i];
	}

	sort(incList, incList + n);	// inOrder Traverse of a BST is an increasing order
	inOrder(root);				// so fill in the tree with an increasing array in inOrder, then a BST is constructed
	levelOrder(root);
	return 0;
}