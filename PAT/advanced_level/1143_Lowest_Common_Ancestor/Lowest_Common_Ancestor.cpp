/*
LCA:
https://github.com/jJayyyyyyy/OJ/blob/master/LeetCode/201-300/P235_Lowest_Common_Ancestor_of_a_BST.cpp

前序中序造树
https://github.com/jJayyyyyyy/OJ/blob/master/tools/Question3.md
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#define MAXSIZE 10001
using namespace std;

struct Node{
	int val;
	Node *lchild, *rchild;
	Node(int v){
		val = v;
		lchild = rchild = NULL;
	}
};

int pre[MAXSIZE] = {0}, in[MAXSIZE] = {0};

Node * inPreCreateTree(int inL, int inR, int preL, int preR){
	if( preL > preR ){
		return NULL;
	}

	int val = pre[preL];
	Node * root = new Node(val);

	int mid;
	for( mid = inL; mid <= inR; mid++ ){
		if( in[mid] == val ){
			break;
		}
	}
	int numLeft = mid - inL;
	root->lchild = inPreCreateTree(inL, mid-1, preL+1, preL+numLeft);
	root->rchild = inPreCreateTree(mid+1, inR, preL+numLeft+1, preR);
	return root;
}

void LCA(Node * root, int lVal, int rVal, bool positionChanged){
	if( root != NULL ){
		if( root->val > lVal && root->val < rVal ){
			if( positionChanged == false ){
				cout<<"LCA of "<<lVal<<" and "<<rVal<<" is "<<root->val<<".\n";
			}else{
				cout<<"LCA of "<<rVal<<" and "<<lVal<<" is "<<root->val<<".\n";
			}
		}else if( root->val == lVal ){
			cout<<lVal<<" is an ancestor of "<<rVal<<".\n";
		}else if( root->val == rVal ){
			cout<<rVal<<" is an ancestor of "<<lVal<<".\n";
		}else if( root->val > rVal ){
			LCA(root->lchild, lVal, rVal, positionChanged);
		}else{
			LCA(root->rchild, lVal, rVal, positionChanged);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin>>m>>n;

	int val;
	unordered_set<int> s;
	for( int i = 0; i < n; i++ ){
		cin>>val;
		in[i] = pre[i] = val;
		s.insert(val);
	}

	sort(in, in+n);

	Node * root = inPreCreateTree(0, n-1, 0, n-1);

	int u, v;
	for( int i = 0; i < m; i++ ){
		cin>>u>>v;
		if( s.find(u) == s.end() && s.find(v) == s.end() ){
			cout<<"ERROR: "<<u<<" and "<<v<<" are not found.\n";
		}else if( s.find(u) == s.end() ){
			cout<<"ERROR: "<<u<<" is not found.\n";
		}else if( s.find(v) == s.end() ){
			cout<<"ERROR: "<<v<<" is not found.\n";
		}else{
			bool positionChanged = false;
			if( u >= v ){
				swap(u, v);
				positionChanged = true;
			}
			LCA(root, u, v, positionChanged);
		}
	}

	return 0;
}
