#include <iostream>
#include <stack>
#define MAXSIZE 32
using namespace std;

struct Node{
	int val=0;
	Node *lchild=NULL, *rchild=NULL;
	Node(int _val){
		val = _val;
	}
};

int pre[MAXSIZE], in[MAXSIZE];
int isFirst = 1;

// 1086, 先序+中序，造树
Node * preInCreate(int preL, int preR, int inL, int inR){
	if( preL > preR ){
		return NULL;
	}
	int val = pre[preL];
	Node * root = new Node(val);

	int mid;
	for( mid = inL; mid <= inR; ++mid ){
		if( in[mid] == val ){
			break;
		}
	}
	int numLeft = mid - inL;
	root->lchild = preInCreate(preL+1, preL+numLeft, inL, mid-1);
	root->rchild = preInCreate(preL+numLeft+1, preR, mid+1, inR);
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

void postTraverse(Node * root){
	if( root != NULL ){
		postTraverse(root->lchild);
		postTraverse(root->rchild);
		disp(root);
	}
}

int main(){
	stack<int> st;
	string s;
	int n, i, j=0, k=0, len, val;
	cin>>n;
	len = n * 2;
	for( i=0; i<len; i++ ){
		cin>>s;
		if( "Push" == s ){
			cin>>val;
			pre[j++] = val;
			st.push(val);
		}else{
			in[k++] = st.top();
			st.pop();
		}
	}
	Node * root = NULL;
	root = preInCreate(0, n-1, 0, n-1);
	postTraverse(root);
	return 0;
}