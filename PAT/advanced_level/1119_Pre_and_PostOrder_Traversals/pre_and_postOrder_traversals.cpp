#include <iostream>
#include <vector>
#define MAXSIZE 32
using namespace std;

int pre[MAXSIZE] = {0};
int post[MAXSIZE] = {0};
bool unique = true;
vector<int> ans_list;

struct Node
{
	int val;
	Node * left, * right;
	Node(int v)
	{
		val = v;
		left = right = NULL;
	}
};

int find_index_of_pretrav_right_child(int valright, int preL, int preR){
	// val is root of right child
	for( int i = preL; i <= preR; i++ )
	{
		if( pre[i] == valright )
		{
			return i;
		}
	}

	// right root not found
	return -1;
}

Node * pre_post(int preL, int preR, int postL, int postR)
{
	if( preL > preR )
	{
		return NULL;
	}

	// find root
	if( pre[preL] == post[postR] )
	{
		int rootval = pre[preL];
		Node * root = new Node(rootval);

		if( postR == 0 )
		{
			return root;
		}
		int valright = post[postR - 1];
		int iright = find_index_of_pretrav_right_child(valright, preL, preR);
		int ileft = preL + 1;

		if( iright == -1 )
		{
			return root;
		}

		// 一个结点可能是根的左孩子也有可能是根的右孩子, 则不唯一
		if( iright <= ileft )
		{
			unique = false;
		}

		int numLeft = iright - ileft;
		root->left  = pre_post(preL + 1, preL + numLeft, postL, postL + numLeft - 1);
		root->right = pre_post(preL + numLeft + 1, preR, postL + numLeft, postR - 1);
		return root;
	}
	else
	{
		return NULL;
	}
}

void in_trav(Node * root)
{
	if( root != NULL )
	{
		in_trav(root->left);
		ans_list.push_back(root->val);
		in_trav(root->right);
	}
}

int main() {
	int n;
	cin>>n;
	for( int i = 0; i < n; i++ )
	{
		cin >> pre[i];
	}

	for ( int i = 0; i < n; i++ )
	{
		cin >> post[i];
	}

	Node * root = pre_post(0, n-1, 0, n-1);
	if( unique == true )
	{
		cout << "Yes\n";
	}
	else
	{
		cout <<"No\n";
	}
	in_trav(root);
	// print_in_trav();
	bool is_first = true;
	for( int val : ans_list )
	{
		if( is_first == true )
		{
			cout << val;
			is_first = false;
		}
		else
		{
			cout << ' ' << val;
		}
	}
	cout << '\n';

	return 0;
}
