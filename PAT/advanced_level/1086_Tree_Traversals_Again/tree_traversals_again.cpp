#include <iostream>
#include <stack>
#define MAXSIZE 32
using namespace std;

struct Node
{
	int val = 0;
	Node *lchild, *rchild;
	Node(int v)
	{
		val = v;
		lchild = rchild = NULL;
	}
};

int pre[MAXSIZE], in[MAXSIZE];
bool is_first = true;
int val_to_index[MAXSIZE] = {0};

// 1086, 先序+中序，造树
Node * in_pre(int preL, int preR, int inL, int inR)
{
	if( preL > preR )
	{
		return NULL;
	}
	int valroot = pre[preL];
	Node * root = new Node(valroot);
	int iroot = val_to_index[valroot];

	int numLeft = iroot - inL;
	root->lchild = in_pre(preL + 1, preL + numLeft, inL, iroot - 1);
	root->rchild = in_pre(preL + numLeft + 1, preR, iroot + 1, inR);
	return root;
}

void post_trav(Node * root)
{
	if( root != NULL )
	{
		post_trav(root->lchild);
		post_trav(root->rchild);
		if( is_first == true )
		{
			is_first = false;
			cout << root->val;
		}
		else
		{
			cout << ' ' << root->val;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int len = n * 2;
	stack<int> stk;
	string s;
	int j = 0, k = 0, val = 0;
	for( int i = 0; i < len; i++ ){
		cin >> s;
		if( "Push" == s )
		{
			cin >> val;
			pre[j++] = val;
			stk.push(val);
		}
		else
		{
			val = stk.top();
			in[k] = val;
			val_to_index[val] = k;
			k++;
			stk.pop();
		}
	}
	Node * root = NULL;
	root = in_pre(0, n - 1, 0, n - 1);
	post_trav(root);
	cout << '\n';
	return 0;
}
