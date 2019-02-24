/*
一般来说，LCA会结合BST进行考察，但是通过这题，我们可以了解到，LCA更深层的是考察左右子树的关系
本题所给的树虽然不是BST，但是通过前序和中序，可以得知某个结点在根的左边还是右边，这样我们就可以套入LCA的通用解法

不要考虑太深，只考虑【根，左子树，右子树】

相当于一边造树，一边LCA

查找LCA，分三种情况

* 如果 p 和 q 在 root 的两边，那么 LCA 就是 root
* 如果 p 和 q 在 root 的左边，那么 root = root->left, 再递归
* 如果 p 和 q 在 root 的右边，那么 root = root->right, 再递归


参考链接
LCA:
https://github.com/jJayyyyyyy/OJ/blob/master/LeetCode/201-300/P235_Lowest_Common_Ancestor_of_a_BST.cpp

前序中序造树
https://github.com/jJayyyyyyy/OJ/blob/master/tools/Question3.md

liuchuo大神的题解
https://www.liuchuo.net/archives/6496

Joy大神的题解
https://www.joyhwong.com/archives/1782

结合 PAT_A_1151, PAT_A_1143 进行了改进, 得到通用模板

*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#define MAXSIZE 10004
using namespace std;

int pre[MAXSIZE] = {0}, in[MAXSIZE] = {0};

// i = val_to_index[val] , 其中 i 是结点 val 在中序序列里的下标
unordered_map<int, int> val_to_index;
int iu, iv;		// iu, iv 是 u, v 在中序序列里的下标
// iu, iv 提取为全局变量, 而不是 LCA 中重复计算, 最高可以从 316ms 降到 161ms
// 若再把 val_to_index 换成如下数组
// short val_to_index[1000004];
// 则时间可以继续提升, 从 161ms 变成 27ms


// 中序前序造树
void inPreCreateTree(int inL, int inR, int preL, int preR, int u, int v)
{
	if( preL > preR )
	{
		return;
	}

	int rootval = pre[preL];
	int iroot = val_to_index[rootval];	// iroot 是根结点 val 在中序序列里的下标
	int numLeft = iroot - inL;		// numLeft 是左子树结点个数

	if( (iroot > iu && iroot < iv) || (iroot < iu && iroot > iv) )
	{
		// u 和 v 在 root 的两侧
		cout << "LCA of " << u << " and " << v << " is " << rootval << ".\n";
	}
	else if( iroot == iu )
	{
		// u 是 LCA
		cout << u << " is an ancestor of " << v << ".\n";
	}
	else if( iroot == iv )
	{
		// v 是 LCA
		cout << v << " is an ancestor of " << u << ".\n";
	}
	else if( iroot > iu && iroot > iv )
	{
		// u 和 v 在 root 的左子树中, 去左子树找
		inPreCreateTree(inL, iroot-1, preL+1, preL+numLeft, u, v);
	}
	else if( iroot < iu && iroot < iv )
	{
		// u 和 v 在 root 的右子树中, 去右子树找
		inPreCreateTree(iroot+1, inR, preL+numLeft+1, preR, u, v);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	int val;
	unordered_set<int> s;
	for( int i = 0; i < n; i++ )
	{
		cin >> val;
		s.insert(val);
		in[i] = val;
		val_to_index[val] = i;
	}

	for( int i = 0; i < n; i++ )
	{
		cin >> pre[i];
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
			iu = val_to_index[u];		// iu 是 u 在中序序列里的下标
			iv = val_to_index[v];		// iv 是 v 在中序序列里的下标
			inPreCreateTree(0, n - 1, 0, n - 1, u, v);
		}
	}

	return 0;
}
