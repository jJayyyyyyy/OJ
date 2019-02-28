/*
1020, 后序 + 中序, 造树
1086, 前序 + 中序, 造树
*/

#include <iostream>
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
int in[MAXSIZE], level[MAXSIZE];
bool is_first = true;

void in_level(Node * & root, int valnode, int inode)
{
	if( root == NULL )
	{
		root = new Node(valnode);
		return;
	}

	int valroot = root->val;
	int iroot = val_to_index[valroot];	// 中轴

	if( inode < iroot )
	{
		in_level(root->lchild, valnode, inode);
	}
	else
	{
		in_level(root->rchild, valnode, inode);
	}
}

void pre_trav(Node * root)
{
	if( root != NULL )
	{
		if( is_first == true )
		{
			cout << root->val;
			is_first = false;
		}
		else
		{
			cout << ' ' << root->val;
		}
		pre_trav(root->lchild);
		pre_trav(root->rchild);
	}
}

void post_trav(Node * root)
{
	if( root != NULL )
	{
		post_trav(root->lchild);
		post_trav(root->rchild);
		if( is_first == true )
		{
			cout << root->val;
			is_first = false;
		}
		else
		{
			cout << ' ' << root->val;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for( int i = 0; i < n; i++ )
	{
		cin>>level[i];
	}
	int val;
	for( int i = 0; i < n; i++ )
	{
		cin >> val;
		in[i] = val;
		val_to_index[val] = i;
	}

	Node * root = NULL;
	for( int i = 0; i < n; i++ )
	{
		int valnode = level[i];
		int inode = val_to_index[valnode];

		in_level( root, valnode, inode );
		// valnode 是子树根结点的值, inode 是子树的根在 in 序列的位置
	}
	is_first = true;
	pre_trav(root);
	cout << '\n';
	is_first = true;
	post_trav(root);
	cout << '\n';

	return 0;
}
