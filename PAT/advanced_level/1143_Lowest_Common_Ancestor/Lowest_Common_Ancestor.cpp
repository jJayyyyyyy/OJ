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

// 如果把 positionChanged 换成全局变量, 就会出现两个 case 无法通过... 
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


/*
柳神给出了一种更加简洁的方法(当题目中的树是 BST , 且输入的是前序时)
不需要造树

也不需要递归地调用 LCA, pre 本身是 DLR
依次遍历 pre (pre[i] 就是子树的根)

*/

/*
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	vector<int> pre(n);
	unordered_set<int> s;
	for( int i = 0; i < n; i++ )
	{
		int val;
		cin >> val;
		pre[i] = val;
		s.insert(val);
	}

	int u, v, rootval;
	for( int i = 0; i < m; i++ )
	{
		cin >> u >> v;
		unordered_set<int>::iterator findu = s.find(u);
		unordered_set<int>::iterator findv = s.find(v);
		if( findu == s.end() && findv == s.end() )
		{
			cout << "ERROR: " << u << " and " << v << " are not found.\n";
		}
		else if( findu == s.end() && findv != s.end() )
		{
			cout << "ERROR: " << u << " is not found.\n";
		}
		else if( findu != s.end() && findv == s.end() )
		{
			cout << "ERROR: " << v << " is not found.\n";
		}
		else
		{
			for( int j = 0; j < n; j++ )
			{
				rootval = pre[j];
				if( ( rootval >= u && rootval <= v ) || ( rootval >= v && rootval <= u ) )
				{
					break;
				}
			}
			if( rootval == u )
			{
				cout << u << " is an ancestor of " << v << ".\n";
			}
			else if( rootval == v )
			{
				cout << v << " is an ancestor of " << u <<".\n";
			}
			else
			{
				cout << "LCA of " << u << " and " << v << " is " << rootval << ".\n";
			}
		}
	}
	return 0;
}
*/

/*
// 结合 PAT_A_1151 进行了改进, 得到通用模板

// 但是会有一个测试点运行超时, 原因未知
// 原来的解法要造树, 新的模板, 同样的方式要造树(遍历树)
// 原来的解法不超时, 新的模板会超时, 但同时, 其他测试点要比原来的模板快, 这就很奇怪了
// ps: 1143 与 1151 有相同的 N, M 范围, 测试数据估计类似, 1151 对应的测试点需要 300+ ms, 确实超过了本题的 200 ms
// 看来本题给定了 BST , 就是要我们在此基础上节省时间
// [已解决]


// 注意, 如果 val_to_index 使用的是 unordered_map, 很有可能超时

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> pre, in;
unordered_map<int, int> val_to_index;
// unordered_map 的 hash 查找很耗时
// 换成如下的 bitmap
// short val_to_index[1000004] = {0};
// 可以将时间 从 160ms 缩短为 37ms
// 注意数组要稍微开大一点, MAXSIZE = 10004 还不够, 会产生段错误
int iu, iv;

void inPreCreateTree(int inL, int inR, int preL, int preR, int u, int v)
{
	if( preL > preR )
	{
		return;
	}

	int rootval = pre[preL];
	int iroot = val_to_index[rootval];
	int numLeft = iroot - inL;
	// 如果把
	// iu = val_to_index[u];
	// iv = val_to_index[v];
	// 放在这里, 就会超时, 而 iu iv 作为 全局变量时, 耗时为 150 ms
	// 可见 unordered_map 的查找 (hash) 也是很耗时的
	// 改进的方法是实验 bitmap (开大数组, 详见上面的注释)

	if( (iroot > iu && iroot < iv) || (iroot < iu && iroot > iv) )
	{
		cout << "LCA of " << u << " and " << v << " is " << rootval << ".\n";
	}
	else if( iroot == iu )
	{
		cout << u << " is an ancestor of " << v << ".\n";
	}
	else if( iroot == iv )
	{
		cout << v << " is an ancestor of " << u << ".\n";
	}
	else if( iroot > iu && iroot > iv )
	{
		inPreCreateTree(inL, iroot - 1, preL + 1, preL + numLeft, u, v);
	}
	else if( iroot < iu && iroot < iv )
	{
		inPreCreateTree(iroot + 1, inR, preL + numLeft + 1, preR, u, v);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	pre.resize(n);
	in.resize(n);
	int val;
	unordered_set<int> s;
	for( int i = 0; i < n; i++ ){
		cin >> val;
		in[i] = pre[i] = val;
		s.insert(val);
	}

	sort(in.begin(), in.end());
	for( int i = 0; i < n; i++ )
	{
		val = in[i];
		val_to_index[val] = i;
	}

	int u, v;
	for( int i = 0; i < m; i++ )
	{
		cin >> u >> v;
		unordered_set<int>::iterator findu = s.find(u);
		unordered_set<int>::iterator findv = s.find(v);
		if( findu == s.end() && findv == s.end() )
		{
			cout << "ERROR: " << u << " and " << v << " are not found.\n";
		}
		else if( findu == s.end() )
		{
			cout << "ERROR: " << u << " is not found.\n";
		}
		else if( findv == s.end() )
		{
			cout << "ERROR: " << v << " is not found.\n";
		}
		else
		{
			iu = val_to_index[u];
			iv = val_to_index[v];
			inPreCreateTree(0, n - 1, 0, n - 1, u, v);
		}
	}

	return 0;
}
*/