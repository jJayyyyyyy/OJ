#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int isFirst=1, isCBT=1, isPreEmpty=0;

struct Node{
	Node *left;
	Node *right;
	int height;
	int value;
	Node(int v){
		left = NULL;
		right = NULL;
		height = 1;
		value = v;
	}
};

int getHeight(Node *parent){
	Node *p = parent;
	if( NULL==p )
		return 0;
	else
		return p->height;
}

int updateHeight(Node *parent){
	Node *p = parent;
	int leftHeight = getHeight(p->left);
	int rightHeight = getHeight(p->right);
	p->height = 1 + max( leftHeight, rightHeight );
	return 1;
}

int getBalanceFactor(Node *parent){
	Node *p = parent;
	return getHeight(p->left) - getHeight(p->right);
}

int leftRotate(Node *&parent){
	Node *tmp = parent->right;
	parent->right = tmp->left;
	tmp->left = parent;
	updateHeight(parent);
	updateHeight(tmp);
	parent = tmp;
	return 1;
}

int rightRotate(Node *&parent){
	Node *tmp = parent->left;
	parent->left = tmp->right;
	tmp->right = parent;
	
	updateHeight(parent);
	updateHeight(tmp);
	parent = tmp;

	return 1;
}

int insertNode(Node *&parent, int value){
	if( parent==NULL ){
		parent = new Node(value);
		return 0;
	}

	if( value < parent->value ){
		insertNode( parent->left, value );
		updateHeight(parent);
		if( 2==getBalanceFactor(parent) ){
			if( 1==getBalanceFactor(parent->left) ){
				rightRotate(parent);
			}else{
				leftRotate(parent->left);
				rightRotate(parent);
			}
		}
	}else{
		insertNode( parent->right, value );
		updateHeight(parent);
		if( -2==getBalanceFactor(parent) ){
			if( -1==getBalanceFactor(parent->right) ){
				leftRotate(parent);
			}else{
				rightRotate(parent->right);
				leftRotate(parent);
			}
		}
	}

	return 0;
}

int output(int value){
	if(isFirst){
		cout<<value;
		isFirst = 0;
	}else{
		cout<<' '<<value;
	}
	
	return 0;
}

//int ldrTraverse(Node *root){
//	Node *p = root;
//	if( NULL==p ){
//		return 0;
//	}
//	ldrTraverse(p->left);
//	output(p->value);
//	ldrTraverse(p->right);
//	return 0;
//}

int levelTraverse(Node *root){
	queue<Node*> q;
	q.push(root);
	while( q.size() ){
		Node *parent = q.front();
		output(parent->value);
		q.pop();

		if( NULL!=parent->left ){
			q.push(parent->left);
			if( isPreEmpty ){
				isCBT = 0;
			}
		}else{
			isPreEmpty = 1;
		}

		if( NULL!=parent->right ){
			q.push(parent->right);
			if( isPreEmpty ){
				isCBT = 0;
			}
		}else{
			isPreEmpty = 1;
		}			
	}
	return 0;
}

int freeTree(Node *root){
	Node *p;
	if( NULL==root ){
		return 0;
	}
	freeTree(root->left);
	p = root->right;
	delete root;
	freeTree(p);
	return 0;
}

int main(){
	int n, i, value;
	Node *root = NULL;

	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>value;
		insertNode(root, value);
	}

	levelTraverse(root);
	if( isCBT ){
		cout<<"\nYES";
	}else{
		cout<<"\nNO";
	}

	freeTree(root);
	return 0;
}
