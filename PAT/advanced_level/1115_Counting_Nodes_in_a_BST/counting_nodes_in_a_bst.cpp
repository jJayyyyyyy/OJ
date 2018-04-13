#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int val, level;
	Node *lchild, *rchild;
	Node(int _val){
		val = _val;
		level = 1;
		lchild = rchild = NULL;
	}
};

int maxLevel1 = -1, maxLevel2 = -1;
int maxCnt1 = 0, maxCnt2 = 0;

void insertBST(Node * & root, int val){
	if( NULL == root ){
		root = new Node(val);
		return;
	}

	if( val <= root->val ){
		insertBST( root->lchild, val );
	}else{
		insertBST( root->rchild, val );
	}
}

void levelTraverse(Node * root){
	queue<Node *> q;
	q.push(root);
	int level = 1;
	while( q.size() ){
		Node * parent = q.front();
		q.pop();
		level = parent->level;
		if( level > maxLevel1 ){
			maxLevel1 = level;
		}
		if( NULL != parent->lchild ){			
			parent->lchild->level = level + 1;
			q.push( parent->lchild );
		}
		if( NULL != parent->rchild ){
			parent->rchild->level = level + 1;
			q.push( parent->rchild );
		}
	}
	maxLevel2 = maxLevel1 - 1;
}

void preTraverse(Node * root){
	if( NULL != root ){
		if( root->level == maxLevel1 ){
			maxCnt1++;
		}else if( root->level == maxLevel2 ){
			maxCnt2++;
		}
		preTraverse(root->lchild);
		preTraverse(root->rchild);
	}
}

int main(){
	Node * root = NULL;
	int n, val;
	cin>>n;

	if( 1 == n ){
		cout<<"1 + 0 = 1\n";
		return 0;
	}

	for( int i = 0; i < n; ++i ){
		cin>>val;
		insertBST(root, val);
	}
	levelTraverse(root);
	preTraverse(root);	// 随便什么遍历都可以，只要能遍历整棵树，然后统计最下两层的结点数即可
	cout<<maxCnt1<<" + "<<maxCnt2<<" = "<<maxCnt1+maxCnt2<<'\n';
	return 0;
}