#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define LEFT 1
#define RIGHT -1
#define MAXSIZE 10004
using namespace std;

struct Student{
	string name;
	int height;
};

struct Node{
	string name;
	Node *lchild, *rchild;
	Node(string _name){
		name = _name;
		lchild = rchild = NULL;
	}
};

Student stuList[MAXSIZE];
vector<string> nameList;

int cmp(Student a, Student b){
	if( a.height != b.height ){
		return a.height > b.height;
	}else{
		return a.name < b.name;
	}
}

// TODO 优化插入耗时
void insertNode(Node * & root, string & name, int direction){
	if( NULL == root ){
		root = new Node(name);
	}else if( direction == LEFT ){
		insertNode(root->lchild, name, direction);
	}else if( direction == RIGHT ){
		insertNode(root->rchild, name, direction);
	}
}

void LDR(Node * root){
	if( NULL != root ){
		LDR(root->lchild);
		nameList.push_back(root->name);
		LDR(root->rchild);
	}
}

// 最后一排
int getLastRow(int n, int k, int offset){
	int col = n / k, remain = n % k;
	col += remain;
	Node *root = NULL;
	int direction = RIGHT;
	for( int i = 0; i < col; ++i ){
		insertNode(root, stuList[i + offset].name, direction);
		direction = -direction;
	}
	LDR(root);
	nameList.push_back("-");
	return col;
}

int getOtherRow(int n, int k, int offset){
	int col = n / k;
	Node * root = NULL;
	int direction = RIGHT;
	for( int i = 0; i < col; ++i ){
		insertNode(root, stuList[i + offset].name, direction);
		direction = -direction;
	}
	LDR(root);
	nameList.push_back("-");
	return offset + col;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N=0, K=0, isFirst=1;
	string name;
	Student stu;
	cin>>N>>K;
	for( int i = 0; i < N; ++i ){
		cin>>stuList[i].name>>stuList[i].height;
	}
	sort( stuList, stuList + N, cmp );

	int offset = getLastRow(N, K, 0);
	for( int i = 0; i < K - 1; ++i ){
		offset = getOtherRow(N, K, offset);
	}

	for(auto item : nameList){
		if( item == "-" ){
			cout<<'\n';
			isFirst = 1;
		}else{
			if( isFirst ){
				cout<<item;
				isFirst = 0;
			}else{
				cout<<' '<<item;
			}		
		}	
	}
	return 0;
}