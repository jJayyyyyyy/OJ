#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
	int val, height;
	Node *lchild, *rchild;
	Node(int _val){
		val = _val;
		height = 1;
		lchild = rchild = NULL;
	}
};

int isCBT=1, isFirst=1;

int getHeight(Node * root){
	if( root == NULL ){
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
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void insertVAL(Node * & root, int val){
	if( NULL == root ){
		root = new Node(val);
		return;
	}

	if( val < root->val ){
		insertVAL(root->lchild, val);
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
		insertVAL(root->rchild, val);
		updateHeight(root);
		if( -2 == getBalanceFactor(root) ){
			if( -1 == getBalanceFactor(root->rchild) ){
				leftRotate(root);
			}else{
				rightRotate(root->rchild);
				leftRotate(root);
			}
		}
	}
}

void visit(Node * root){
	if( root != NULL ){
		if( isFirst ){
			cout<<root->val;
			isFirst = 0;
		}else{
			cout<<' '<<root->val;
		}
	}
}

void isCBTLevelTrav(Node * root){
	if( root != NULL ){
		queue<Node *> q;
		q.push(root);
		while( q.size() > 0 ){
			Node * node = q.front();
			visit(node);
			q.pop();
			if( node != NULL ){
				q.push(node->lchild);
				q.push(node->rchild);
			}else{
				while( q.size() > 0 ){
					Node * p = q.front();
					if( p != NULL ){
						isCBT = 0;
						break;
					}
					q.pop();
				}		
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
		insertVAL(root, val);
	}

	isCBTLevelTrav(root);
	if( isCBT ){
		cout<<"\nYES\n";
	}else{
		cout<<"\nNO\n";
	}
	return 0;
}