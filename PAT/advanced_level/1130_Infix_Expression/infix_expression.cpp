#include <iostream>
#include <string>
#define MAXSIZE 32
using namespace std;

struct Node{
	string val;
	int parent=-1, lchild=-1, rchild=-1;
	void set(string _v, int _l, int _r){
		val = _v;
		lchild = _l;
		rchild = _r;
	}
};

Node node[MAXSIZE];
string expression = "";
int ROOT;

void inOrder(int root){
	if( root != -1 ){
		bool hasParenthsis = false;
		if( root != ROOT ){			// 最外层的表达式不需要括号
			if( node[root].lchild != -1 || node[root].rchild != -1 ){	// 如果不是叶节点，就要加括号
				hasParenthsis = true;
			}
		}

		// (lVal + op + rVal)的结构
		if( true == hasParenthsis ){
			expression += "(";
		}
		inOrder(node[root].lchild);
		expression += node[root].val;
		inOrder(node[root].rchild);
		if( true == hasParenthsis ){
			expression += ")";
		}
	}
}

int main(){
	string val;
	int n, i, lchild, rchild;
	cin>>n;
	for( i = 1; i <= n; ++i ){
		cin>>val>>lchild>>rchild;
		node[i].set(val, lchild, rchild);
		node[lchild].parent = i;
		node[rchild].parent = i;
	}
	for( i = 1; i <= n; ++i ){
		if( -1 == node[i].parent ){
			ROOT = i;
			break;
		}
	}
	inOrder(ROOT);
	cout<<expression<<'\n';
	return 0;
}
