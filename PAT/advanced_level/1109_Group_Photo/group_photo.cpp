#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10008
using namespace std;

struct Student{
	string name;
	int height;
};

Student seq[MAX];
int ix=0;

struct Node{
	Student stu;
	struct Node *left;
	struct Node *right;
	Node(){ left=NULL; right=NULL; }
};

int FreeTree(Node *root){
	if(root!=NULL){
		FreeTree(root->left);
		FreeTree(root->right);
		delete root;
	}
	return 1;
}

int LDR(Node *root){
	if(root!=NULL){
		LDR(root->left);
		seq[ix++] = root->stu;
		LDR(root->right);
	}
	return 1;
}

Node *NewNode(Student *stu){
	Node *node = new Node;
	node->stu = *stu;
	return node;
}

Node *InsertLeft(Node *parent, Student *stu){
	Node *node = NewNode(stu);
	parent->left = node;
	return node;
}

Node *InsertRight(Node *parent, Student *stu){
	Node *node = NewNode(stu);
	parent->right = node;
	return node;
}

int cmp(Student a, Student b){
	if( a.height!=b.height)
		return a.height>b.height;
	else
		return a.name<b.name;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int us_N=0, us_K=0, height=0, i=0, j=0;
	string name;

	cin>>us_N>>us_K;
	Student stu_list[MAX];
	for( i=0; i<us_N; i++ )
		cin>>stu_list[i].name>>stu_list[i].height;

	sort(&stu_list[0], &stu_list[us_N], cmp);

	int m=us_N/us_K, r=us_N%us_K, col, dir;
	Student *data=&stu_list[0], *output=&seq[0];
	Node *root=NewNode(data++), *parent, *left, *right;

	// row[K]
	dir = 1;
	parent = root;
	left = parent;
	right = parent;
	col = m + r;
	for( i=1; i<col; i++ ){
		if( 1==dir )
			left = InsertLeft(left, data++);
		else
			right = InsertRight(right, data++);
		dir = -dir;
	}
	LDR(parent);
	for( i=0; i<col-1; i++ )
		cout<<output[i].name<<' ';
	cout<<output[i].name<<'\n';
	output = &output[i+1];

	// row[k-1]~row[1]
	for( j=1; j<us_K; j++){
		dir = 1;
		parent = InsertRight(right, data++);
		left = parent;
		right = parent;
		col = m;
		for( i=1; i<col; i++ ){
			if( 1==dir )
				left = InsertLeft(left, data++);
			else
				right = InsertRight(right, data++);
			dir = -dir;
		}
		LDR(parent);
		for( i=0; i<col-1; i++ )
			cout<<output[i].name<<' ';
		cout<<output[i].name<<'\n';
		output = &output[i+1];
	}

	FreeTree(root);
	return 0;
}