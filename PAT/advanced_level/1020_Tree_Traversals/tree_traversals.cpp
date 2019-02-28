/*
1020, 后序 + 中序, 造树
1086, 前序 + 中序, 造树
*/
#include <iostream>
#include <queue>
#define MAXSIZE 32
using namespace std;

struct Node
{
	int val;
	Node *lchild, *rchild;
	Node( int v )
	{
		val = v;
		lchild = rchild = NULL;
	}
};

int val_to_index[MAXSIZE] = {0};
int in[MAXSIZE], post[MAXSIZE], pre[MAXSIZE];

Node * in_post(int inL, int inR, int postL, int postR)
{
	if( postL > postR )
	{
		return NULL;
	}

	int rootval = post[postR];
	Node * root = new Node(rootval);

	int iroot = val_to_index[rootval];
	int numLeft = iroot - inL;

	root->lchild = in_post(inL, iroot - 1, postL, postL + numLeft - 1);
	root->rchild = in_post(iroot + 1, inR, postL + numLeft, postR - 1);
	return root;
}

void level_trav(Node * root)
{
	queue<Node *> q;
	q.push(root);
	bool is_first = true;

	while( q.size() != 0 )
	{
		Node * parent = q.front();
		q.pop();
		if( is_first == true )
		{
			cout << parent->val;
			is_first = false;
		}
		else
		{
			cout << ' ' << parent->val;
		}
		if( parent->lchild != NULL )
		{
			q.push(parent->lchild);
		}
		if( parent->rchild != NULL )
		{
			q.push(parent->rchild);
		}
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for( int i = 0; i < n; i++ )
	{
		cin >> post[i];
	}
	int val;
	for( int i = 0; i < n; i++ )
	{
		cin >> val;
		in[i] = val;
		val_to_index[val] = i;
	}
	Node * root = in_post(0, n - 1, 0, n - 1);
	level_trav(root);

	return 0;
}
