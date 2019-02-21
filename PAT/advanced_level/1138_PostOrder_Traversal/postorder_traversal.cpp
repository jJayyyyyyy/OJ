#include <iostream>
#define MAXSIZE 50004
using namespace std;

struct Node{
	int val;
	Node *lchild, *rchild;
	Node(int _val){
		val = _val;
		lchild = rchild = NULL;
	}
};

int pre[MAXSIZE], in[MAXSIZE], isFirst=1;

// 参数都是 pre 或 in 的下标
// 范围 [L, R]，闭区间
Node * inPre(int inL, int inR, int preL, int preR){
	if( preL > preR ){
		return NULL;
	}
	int val = pre[preL]; // root的值
	Node * root = new Node(val);

	int mid;	// 寻找 in 中序的root
	for( mid = inL; mid <= inR; mid++ ){
		if( in[mid] == val ){
			break;
		}
	}

	int numLeft = mid - inL;
	// 前序，每个子序列的第一个节点，就是子树的根
	root->lchild = inPre(inL, mid-1, preL+1, preL+numLeft);
	root->rchild = inPre(mid+1, inR, preL+numLeft+1, preR);
	return root;
}

void visit(int val){
	if( isFirst ){
		cout<<val<<'\n';
		isFirst = 0;
	}
}

void postTrav(Node * root){
	if( root != NULL && isFirst ){
		postTrav(root->lchild);
		postTrav(root->rchild);
		visit(root->val);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;

	cin>>n;
	for( int i = 0; i < n; i++ ){
		cin>>pre[i];
	}

	for( int i = 0 ; i < n; i++ ){
		cin>>in[i];
	}

	Node * root = NULL;
	root = inPre(0, n-1, 0, n-1);
	postTrav(root);
	return 0;
}


/*
// 时间限制似乎修改过了, 时间要求更加严格了
// 因此需要对原来的算法进行改进
// 由于后序遍历是 LRD
// 后序的第一个结点就是 最底一层的最左边的结点
// 也就是说, 在 【中序 + 前序】 造树的过程中 我们只需要找到第一次返回结点即可退出
// 对原来程序稍作修改, 提前退出程序, 运行最大的 case 时可以比原来减少至少 150ms 运行时间

#include <iostream>
#define MAXSIZE 50004
using namespace std;

struct Node
{
	int val;
	Node *lchild, *rchild;
	Node(int _val)
	{
		val = _val;
		lchild = rchild = NULL;
	}
};

int pre[MAXSIZE], in[MAXSIZE], isFirst = 1;

// 参数都是 pre 或 in 的下标
// 范围 [L, R]，闭区间
Node * in_pre(int inL, int inR, int preL, int preR)
{
	if( preL > preR )
	{
		return NULL;
	}
	int val = pre[preL]; // root的值
	Node * root = new Node(val);

	int mid;	// 寻找 in 中序的root
	for( mid = inL; mid <= inR; mid++ )
	{
		if( in[mid] == val )
		{
			break;
		}
	}

	int numLeft = mid - inL;
	// 前序，每个子序列的第一个节点，就是子树的根
	root->lchild = inPre(inL, mid-1, preL+1, preL+numLeft);
	root->rchild = inPre(mid+1, inR, preL+numLeft+1, preR);
	// 在这里输出
	cout << root->val << '\n';
	exit(0);
	// 并提前退出程序
	return root;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;

	cin>>n;
	for( int i = 0; i < n; i++ )
	{
		cin >> pre[i];
	}

	for( int i = 0 ; i < n; i++ )
	{
		cin >> in[i];
	}

	Node * root = in_pre(0, n-1, 0, n-1);
	return 0;
}

*/