#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#define MAX 32
#define NONE -1
using namespace std;

struct Node{
	int lchild, rchild, parent;
	Node(){
		lchild = rchild = parent = NONE;
	}
};

Node nodeList[MAX];
vector<int> levelOrderList;

int isCBTLevelTrav(int root){
	if( root != NONE ){
		queue<int> q;
		q.push(root);
		while( q.size() > 0 ){
			int node = q.front();
			levelOrderList.push_back(node);
			// visit(node);
			q.pop();
			if( node != NONE ){
				q.push(nodeList[node].lchild);
				q.push(nodeList[node].rchild);
			}else{
				while( q.size() > 0 ){
					int p = q.front();
					if( p != NONE ){
						return 0;
					}
					q.pop();
				}
			}
		}
	}
	return 1;
}

int str2num(string s){
	stringstream ss(s);
	int num;
	ss>>num;
	return num;
}

int main(){
	int n, i;
	string left, right;
	int lchild, rchild, parent, root;

	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>left>>right;
		if( "-" != left ){
			lchild = str2num(left);
			parent = i;
			nodeList[parent].lchild = lchild;
			nodeList[lchild].parent = parent;
		}
		if( "-" != right ){
			rchild = str2num(right);
			parent = i;
			nodeList[parent].rchild = rchild;
			nodeList[rchild].parent = parent;
		}
	}

	for( i=0; i<n; i++ ){
		if( NONE == nodeList[i].parent ){
			root = i;
			break;
		}
	}

	int isCBT = isCBTLevelTrav(root);
	if( isCBT ){
		cout<<"YES "<<levelOrderList[n - 1];
	}else{
		cout<<"NO "<<root;
	}
	return 0;
}
