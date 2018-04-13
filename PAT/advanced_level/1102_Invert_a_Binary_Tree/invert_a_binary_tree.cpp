#include <iostream>
#include <cctype>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXSIZE 16
using namespace std;

struct Node{
	int parent, lchild, rchild;				// parent 用于寻找根结点，根结点的 parent 为 -1
	Node(){
		parent = lchild = rchild = -1;
	}
};

Node node[MAXSIZE];
vector<int> ans;

/*	反转二叉树
	先反转根结点的左子树，再反转右子树
	然后反转根结点的左右孩子
*/
void invertTree(int root){
	if( root != -1 ){
		invertTree(node[root].lchild);
		invertTree(node[root].rchild);
		swap( node[root].lchild, node[root].rchild );
	}
}

// 层序遍历
void levelOrderTrav(int root){
	queue<int> q;
	q.push(root);
	while( q.size() ){
		int parent = q.front();
		ans.push_back(parent);
		q.pop();
		if( node[parent].lchild != -1 ){
			q.push( node[parent].lchild );
		}
		if( node[parent].rchild != -1 ){
			q.push( node[parent].rchild );
		}
	}
}

// 中序遍历
void inOrderTrav(int root){
	if( -1 != root ){
		inOrderTrav(node[root].lchild);
		ans.push_back(root);
		inOrderTrav(node[root].rchild);
	}
}

void output(){
	int isFirst = 1;
	for( int i = 0; i < ans.size(); ++i ){
		if( isFirst ){
			cout<<ans[i];
			isFirst = 0;
		}else{
			cout<<' '<<ans[i];
		}
	}
	cout<<'\n';
	ans.clear();
}

int main(){
	int n;
	char c1, c2;
	cin>>n;
	for( int i = 0; i < n; ++i ){
		cin>>c1>>c2;
		if( isdigit(c1) ){
			node[i].lchild = c1 - '0';
			node[c1 - '0'].parent = i;
		}
		if( isdigit(c2) ){
			node[i].rchild = c2 - '0';
			node[c2 - '0'].parent = i;
		}
	}

	int root = -1;
	// 寻找根结点
	for( int i = 0; i < n; ++i ){
		if( -1 == node[i].parent ){
			root = i;
			break;
		}
	}

	invertTree(root);
	levelOrderTrav(root);
	output();
	inOrderTrav(root);
	output();
	return 0;
}