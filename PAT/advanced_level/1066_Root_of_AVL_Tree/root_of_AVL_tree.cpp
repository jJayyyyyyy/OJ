#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	Node *lchild, *rchild;
	int val, height;
	Node(int _val){
		val = _val;
		height = 1;
		lchild = rchild = NULL;
	}
};

int getHeight(Node * root){
	if( NULL == root ){
		return 0;
	}else{
		return root->height;
	}
}

void updateHeight(Node * root){
	int lH = getHeight(root->lchild);
	int rH = getHeight(root->rchild);
	root->height = max(lH, rH) + 1;
}

int getBalanceFactor(Node * root){
	int lH = getHeight(root->lchild);
	int rH = getHeight(root->rchild);
	return lH - rH;
}

void leftRotate(Node * & root){
	Node * tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void rightRotate(Node * & root){
	Node * tmp = root->lchild;
	root->rchild = tmp->rchild;
	tmp->rchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void insertAVL(Node * & root, int val){
	if( NULL == root ){
		root = new Node(val);
		return;
	}

	if( val < root->val ){
		insertAVL(root->lchild, val);
		updateHeight(root);
		if( 2 == getBalanceFactor(root) ){
			if( 1 == getBalanceFactor(root->lchild) ){
				rightRotate(root);
			}else{
				leftRotate(root->lchild);
				rightRotate(root);
			}
		}
	}else{
		insertAVL(root->rchild, val);
		updateHeight(root);
		if( -2 == getBalanceFactor(root) ){
			if( -1 ==getBalanceFactor(root->rchild) ){
				leftRotate(root);
			}else{
				rightRotate(root->rchild);
				leftRotate(root);
			}
		}
	}
}

int main(){
	Node * root = NULL;
	int n, i, val;
	cin>>n;
	for( i = 0; i < n; ++i ){
		cin>>val;
		insertAVL(root, val);
	}
	cout<<root->val<<'\n';
	return 0;
}
