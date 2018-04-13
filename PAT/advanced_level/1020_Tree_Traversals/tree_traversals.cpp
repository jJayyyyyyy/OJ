#include <iostream>
#include <queue>
#define MAXSIZE 32
using namespace std;

struct Node{
	int val=0;
	Node *lchild=NULL, *rchild=NULL;
	Node(int _val){
		val = _val;
	}
};

int in[MAXSIZE], post[MAXSIZE];
int isFirst = 1;

// 1020, 后序+中序，造树
Node * postInCreate(int postL, int postR, int inL, int inR){
	if( postL > postR ){
		return NULL;
	}
	int val = post[postR];
	Node * root = new Node(val);

	int mid;
	for( mid = inL; mid <= inR; ++mid ){
		if( in[mid] == val ){
			break;
		}
	}
	int numLeft = mid - inL;
	root->lchild = postInCreate(postL, postL+numLeft-1, inL, mid-1);
	root->rchild = postInCreate(postL+numLeft, postR-1, mid+1, inR);
	return root;
}

void disp(Node * p){
	if( isFirst ){
		isFirst = 0;
		cout<<p->val;
	}else{
		cout<<' '<<p->val;
	}
}

void levelTrav(Node * root){
	queue<Node *> q;
	q.push(root);
	while( q.size() > 0 ){
		Node * node = q.front();
		q.pop();
		disp(node);
		if( node->lchild != NULL ){
			q.push(node->lchild);
		}
		if( node->rchild != NULL ){
			q.push(node->rchild);
		}
	}
}

int main(){
	int n, i;
	cin>>n;
	for( i = 0; i < n; ++i ){
		cin>>post[i];
	}
	for( i = 0; i < n; ++i ){
		cin>>in[i];
	}
	Node * root = NULL;
	root = postInCreate(0, n-1, 0, n-1);
	levelTrav(root);
	return 0;
}