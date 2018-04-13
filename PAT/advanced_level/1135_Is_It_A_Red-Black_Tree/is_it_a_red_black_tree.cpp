#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> pre, in, post, ori;

struct Node{
	int val;
	Node *lchild, *rchild;
	Node(int _val){
		val = _val;
		lchild = rchild = NULL;
	}
};

void insert(Node * & root, int val){
	if( root == NULL ){
		root = new Node(val);
	}else if( abs(val) < abs(root->val) ){
		insert(root->lchild, val);
	}else{
		insert(root->rchild, val);
	}
}

void inOrderTrav(Node * root){
	if( root != NULL ){
		inOrderTrav(root->lchild);
		in.push_back(root->val);
		inOrderTrav(root->rchild);
	}
}

bool cmp(int a, int b){
	return abs(a) < abs(b);
}

bool isBST(Node * root){
	in.clear();
	inOrderTrav(root);
	sort(pre.begin(), pre.end(), cmp);
	for( int i = 0; i < pre.size(); ++i ){
		if( pre[i] != abs( in[i] ) ){
			return false;
		}
	}
	return true;
}

bool isRed(Node * root){
	if( root != NULL ){
		return root->val < 0;
	}else{
		return false;
	}
}

bool isRootBlack(Node * root){
	return root->val >= 0;
}

bool judge_3_4(Node * root){
	if( root == NULL ){
		return true;
	}else if( isRed(root) ){
		if( root->lchild != NULL && isRed(root->lchild) ){
			return false;
		}
		if( root->rchild != NULL && isRed(root->rchild) ){
			return false;
		}
	}
	return judge_3_4(root->lchild) && judge_3_4(root->rchild);
}

int cntBlack(Node * root){
	if( root == NULL ){
		return 0;
	}
	int lB = cntBlack(root->lchild);
	int rB = cntBlack(root->rchild);
	return max(lB, rB) + isRootBlack(root);
}

bool judge_5(Node * root){
	if( root == NULL ){
		return true;
	}
	int lB = cntBlack(root->lchild);
	int rB = cntBlack(root->rchild);
	if( lB != rB ){
		return false;
	}else{
		judge_5(root->lchild) && judge_5(root->rchild);
	}
}

int main(){
	int k, n;
	cin>>k;
	for( int i = 0; i < k; ++i ){
		cin>>n;
		ori.resize(n);
		pre.resize(n);
		Node * root = NULL;
		for( int j = 0; j < n; ++j ){
			cin>>ori[j];
			insert( root, ori[j] );
			pre[j] = abs( ori[j] );
		}
		if( isBST(root) == false ){
			cout<<"No\n";
		}else if( isRootBlack(root) == false ){
			cout<<"No\n";
		}else if( judge_3_4(root) == false ){
			cout<<"No\n";
		}else if(judge_5(root) == false ){
			cout<<"No\n";
		}else{
			cout<<"Yes\n";
		}
	}
	return 0;
}