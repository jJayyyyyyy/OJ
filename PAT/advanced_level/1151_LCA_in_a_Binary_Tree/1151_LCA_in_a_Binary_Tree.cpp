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
*/


#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
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

// val2ix is a map that converts val to index in in[] sequence
unordered_map<int, int> val2ix;

Node * inPreCreateTree(int inL, int inR, int preL, int preR){
	if( preL > preR ){
		return NULL;
	}

	int valRoot = pre[preL];
	Node * root = new Node(valRoot);

	int mid;
	for( mid = inL; mid < inR; mid++ ){
		if( in[mid] == valRoot ){
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

// preRoot is the index of Root in pre[] sequence, 相当于preL
// inL is the left bound of in[] sequence
// inR is the right bound of in[] sequence
// inRoot is the index of Root in in[] sequence
void LCA(int preRoot, int inL, int inR, int valU, int valV){
	if( inL <= inR ){
		int valRoot = pre[preRoot];
		int inRoot = val2ix[valRoot];
		int numLeft = inRoot - inL;
		int inU = val2ix[valU];
		int inV = val2ix[valV];

		// u 和 v 在 root 的两侧
		if( inRoot > inU && inRoot < inV ){
			cout<<"LCA of "<<valU<<" and "<<valV<<" is "<<valRoot<<".\n";
		}else if( inRoot < inU && inRoot > inV ){
			cout<<"LCA of "<<valU<<" and "<<valV<<" is "<<valRoot<<".\n";
		}

		// u 是 LCA
		else if( inRoot == inU ){
			cout<<valU<<" is an ancestor of "<<valV<<".\n";
		}

		// v 是 LCA
		else if( inRoot == inV ){
			cout<<valV<<" is an ancestor of "<<valU<<".\n";
		}

		// u 和 v 在 root 的左子树中, 去左子树找
		else if( inRoot > inU && inRoot > inV ){
			LCA(preRoot+1, inL, inRoot-1, valU, valV);
		}

		// u 和 v 在 root 的右子树中, 去右子树找
		else if( inRoot < inU && inRoot < inV ){
			LCA(preRoot+numLeft+1, inRoot+1, inR, valU, valV);
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
	for( int i = 1; i <= n; i++ ){
		cin>>val;
		s.insert(val);
		in[i] = val;
		val2ix[val] = i;
	}
	for( int i = 1; i <= n; i++ ){
		cin>>pre[i];
	}

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
			LCA(1, 1, n, u, v);
		}
	}

	return 0;
}