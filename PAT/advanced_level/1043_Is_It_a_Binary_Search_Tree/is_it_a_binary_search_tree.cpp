#include <iostream>
#define MAX 1004
using namespace std;

int inputList[MAX] = {0};
int preList[MAX] = {0};
int mirrorPreList[MAX] = {0};
int iInput=0, iPre=0, iMirror=0, isFirst = 1;

struct Node{
	int val;
	Node *lchild=NULL, *rchild=NULL;
	Node(int _val){
		val = _val;
	}
};

void insertBST(Node * &root, int val){
	if( NULL == root ){
		root = new Node(val);
		return;
	}

	if( val < root->val ){
		insertBST(root->lchild, val);
	}else{
		insertBST(root->rchild, val);
	}
}

void preTrav(Node * root){
	if( NULL != root ){
		preList[iPre++] = root->val;
		preTrav(root->lchild);
		preTrav(root->rchild);
	}
}

void mirrorPreTrav(Node * root){
	if( NULL != root ){
		mirrorPreList[iMirror++] = root->val;
		mirrorPreTrav(root->rchild);
		mirrorPreTrav(root->lchild);
	}
}

void output(const int val){
	if( isFirst ){
		cout<<val;
		isFirst = 0;
	}else{
		cout<<' '<<val;
	}
}

void postTrav(const Node * root){
	if( NULL != root ){
		postTrav(root->lchild);
		postTrav(root->rchild);
		output(root->val);
	}
}

void mirrorPostTrav(const Node * root){
	if( NULL != root ){
		mirrorPostTrav(root->rchild);
		mirrorPostTrav(root->lchild);
		output(root->val);
	}
}

bool cmp(const int a[], const int b[], const int len){
	for( int i=0; i<len; i++ ){
		if( a[i] != b[i] ){
			return false;
		}
	}
	return true;
}

int main(){
	Node *root = NULL;
	int val, n, i;
	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>val;
		inputList[iInput++] = val;
		insertBST(root, val);
	}

	preTrav(root);
	mirrorPreTrav(root);
	if( true == cmp(inputList, preList, n) ){
		cout<<"YES\n";
		postTrav(root);
	}else if( true == cmp(inputList, mirrorPreList, n) ){
		cout<<"YES\n";
		mirrorPostTrav(root);
	}else{
		cout<<"NO\n";
	}
	return 0;
}
