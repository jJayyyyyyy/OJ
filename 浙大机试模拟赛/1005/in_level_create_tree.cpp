#include <iostream>
#include <vector>
#include <queue>
#define MAXSIZE 32
using namespace std;

struct Node{
	int val;
	Node *lchild, *rchild;
	Node(int v){
		val = v;
		lchild = rchild = NULL;
	}
};

int in[MAXSIZE], level[MAXSIZE];
int n;
vector<int> pre, post;

void create(Node * & root, int val, int childRootIndex){
	if( root == NULL ){
		root = new Node(val);
		return;
	}

	int rootIndex;	// 中轴
	for( rootIndex = 0; rootIndex < n; rootIndex++ ){
		if( in[rootIndex] == root->val ){
			break;
		}
	}

	if( childRootIndex <= rootIndex ){
		create(root->lchild, val, childRootIndex);
	}else{
		create(root->rchild, val, childRootIndex);
	}
}

void preTrav(Node * root){
	if( root != NULL ){
		pre.push_back(root->val);
		preTrav(root->lchild);
		preTrav(root->rchild);
	}
}

void postTrav(Node * root){
	if( root != NULL ){
		postTrav(root->lchild);
		postTrav(root->rchild);
		post.push_back(root->val);
	}
}

void printPrePost(int len){
	for( int i = 0; i < len; i++ ){
		if( i != 0 ){
			cout<<' ';
		}
		cout<<pre[i];
	}
	cout<<'\n';
	for( int i = 0; i < len; i++ ){
		if( i != 0 ){
			cout<<' ';
		}
		cout<<post[i];
	}
	cout<<'\n';
}

int main(){
	cin>>n;
	for( int i = 0; i < n; i++ ){
		cin>>level[i];
	}
	for( int i = 0; i < n; i++ ){
		cin>>in[i];
	}

	Node * root=NULL;
	int valRoot;
	for(int i = 0; i < n; i++ ){
		int childRootIndex;
		for( childRootIndex = 0; childRootIndex < n; childRootIndex++ ){
			if( in[childRootIndex] == level[i] ){
				valRoot = in[childRootIndex];
				break;
			}
		}
		create( root, valRoot, childRootIndex );
		// val是root的值, childRootIndex 是 子树的根在in序列的位置
	}

	preTrav(root);
	postTrav(root);
	printPrePost(n);

	return 0;
}


/*
#include <iostream>
#include <vector>
#include <queue>
#define MAXSIZE 32
using namespace std;

struct Node{
	int val;
	Node *lchild, *rchild;
	Node(int v){
		val = v;
		lchild = rchild = NULL;
	}
};

int in[MAXSIZE], level[MAXSIZE];
int n;
vector<int> pre, post;

void create(Node * & root, int val, int iChild){
	if( root == NULL ){
		root = new Node(val);
		return;
	}

	int iRoot;	// 中轴
	for( iRoot = 0; iRoot < n; iRoot++ ){
		if( in[iRoot] == root->val ){
			break;
		}
	}

	if( iChild <= iRoot ){
		create(root->lchild, val, iChild);
	}else{
		create(root->rchild, val, iChild);
	}
}

int main(){
	cin>>n;
	for( int i = 0; i < n; i++ ){
		cin>>level[i];
	}
	for( int i = 0; i < n; i++ ){
		cin>>in[i];
	}

	Node * root=NULL;
	int valChildRoot, iChild;
	for(int i = 0; i < n; i++ ){
		for( iChild = 0; iChild < n; iChild++ ){
			if( in[iChild] == level[i] ){
				valChildRoot = in[iChild];
				break;
			}
		}
		create( root, valChildRoot, iChild );
		// val是root的值, iChild 是 子树的根在in序列的位置
	}

	return 0;
}
*/