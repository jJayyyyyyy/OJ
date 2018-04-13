#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#define MAXSIZE 32
using namespace std;

struct Node{
	int val, level;
	Node *lchild, *rchild;
	Node(int v){
		val = v;
		level = 1;
		lchild = rchild = NULL;
	}
};

int in[MAXSIZE], post[MAXSIZE];
vector<Node *> levelList;
stack<int> st;
vector<int> ans;

void getAllStack(){
	while( st.size() != 0 ){
		ans.push_back(st.top());
		st.pop();
	}
}

void zigzag(){
	for( auto node : levelList ){
		if( node->level % 2 == 1 ){
			st.push(node->val);
		}else{
			getAllStack();
			ans.push_back(node->val);
		}
	}
	getAllStack();
}

void vis(Node * node){
	levelList.push_back(node);
}

void levelTrav(Node * root){
	queue<Node *> q;
	q.push(root);
	while( q.size() ){
		Node * node = q.front();
		vis(node);
		q.pop();
		if( node->lchild != NULL ){
			node->lchild->level = node->level + 1;
			q.push(node->lchild);
		}
		if( node->rchild != NULL ){
			node->rchild->level = node->level + 1;
			q.push(node->rchild);
		}
	}
}

Node * inPost(int inL, int inR, int postL, int postR){
	if( postL > postR ){
		return NULL;
	}
	int val = post[postR];
	Node * root = new Node(val);

	int mid;
	for( mid = inL; mid <= inR; mid++ ){
		if( in[mid] == val ){
			break;
		}
	}
	int numLeft = mid - inL;
	root->lchild = inPost(inL, mid-1, postL, postL+numLeft-1);
	root->rchild = inPost(mid+1, inR, postL+numLeft, postR-1);
	return root;
}

void printAns(){
	cout<<ans[0];
	for( int i = 1; i < ans.size(); i++ ){
		cout<<' '<<ans[i];
	}
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;

	for( int i = 0; i < n; i++ ){
		cin>>in[i];
	}
	for( int i = 0; i < n; i++ ){
		cin>>post[i];
	}

	Node * root = inPost(0, n-1, 0, n-1);
	levelTrav(root);
	zigzag();
	printAns();
	return 0;
}