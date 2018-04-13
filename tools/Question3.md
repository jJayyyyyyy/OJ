##	树

*	数据结构

	```cpp
	struct Node{
		int val, level;
		Node *lchild, *rchild;
		Node(int _val){
			val = _val;
			level = 1;
			lchild = rchild = NULL;
		}
	}
	```

*	inPre,	中序 + 前序 造树

	```cpp
	Node * inPre(int inL, int inR, int preL, int preR){
		if( preL > preR ){
			return NULL;
		}
		int val = pre[preL];
		Node * root = new Node(val);
	
		int mid;
		for( mid = inL; mid <= inR; mid++ ){
			if( in[inL] == val ){
				break;
			}
		}
	
		int numLeft = mid - inL;
		root->lchild = inPre(inL, mid-1, preL+1, preL+numLeft);
		root->rchild = inPre(mid+1, inR, preL+numLeft+1, preR);
		return root;
	}
	```

*	inLevel

	参考[浙大机试模拟赛-1005](https://logn.me/problem/1005)
	
	```cpp
	#include <iostream>
	#include <vector>
	#include <queue>
	#define MAXSIZE 32
	using namespace std;
	
	struct Node{
		int val;
		Node *lchild, *rchild;
		Node(int v){
			val = v;
			lchild = rchild = NULL;
		}
	};
	
	int in[MAXSIZE], level[MAXSIZE];
	int n;
	vector<int> pre, post;
	
	void create(Node * & root, int val, int iChild){
		if( root == NULL ){
			root = new Node(val);
			return;
		}
	
		int iRoot;	// 中轴
		for( iRoot = 0; iRoot < n; iRoot++ ){
			if( in[iRoot] == root->val ){
				break;
			}
		}
	
		if( iChild <= iRoot ){
			create(root->lchild, val, iChild);
		}else{
			create(root->rchild, val, iChild);
		}
	}
	
	int main(){
		cin>>n;
		for( int i = 0; i < n; i++ ){
			cin>>level[i];
		}
		for( int i = 0; i < n; i++ ){
			cin>>in[i];
		}
	
		Node * root=NULL;
		int valChild, iChild;
		for(int i = 0; i < n; i++ ){
			for( iChild = 0; iChild < n; iChild++ ){
				if( in[iChild] == level[i] ){
					valChild = in[iChild];
					break;
				}
			}
			create( root, valChild, iChild );
			// valChild 是 child 的值, iChild 是 子树的根在in序列的位置
		}
	
		return 0;
	}
	```

*	levelTraverse,	层序遍历

	```cpp
	void levelTraverse(Node * root){
		queue<Node *> q;
		q.push(root);
		while( q.size() ){
			Node * parent = q.front();
			visit(parent);
			q.pop();
	
			if( parent->lchild != NULL ){
				parent->lchild->level = parent->level + 1;
				q.push(parent->lchild);
			}
			if( parent->rchild != NULL ){
				parent->rchild->level = parent->level + 1;
				q.push(parent->rchild);
			}
		}
	}
	```

##	图

*	DFS

*	BFS

*	连通图

	```cpp
	/* DFS
	** param @v --- 节点ID
	*/
	void DFS(int v){
		vis[v] = true;
		for( auto next : G[v] ){
			if( vis[next] == false ){
				DFS(next);
			}
		}
	}
	
	/* 获得连通块的个数
	** param @n --- 总的节点数, [1, n]
	*/
	int getBlock(int n){
		int block = 0;
		for( int i = 1; i <= n; i++ ){
			if( vis[i] == false ){
				DFS(i);
				block++;
			}
		}
		return block;
	}
	```
	
*   边的遍历, PAT_A_1134

	```
	vector<int> edgeOfV[MAXSIZE];
	bool visE[MAXSIZE];

	for( int eID = 0; eID < m; ++eID ){
		cin>>v1>>v2;
		
		// 给每条边编号, [0, m-1]
		edgeOfV[v1].push_back(eID);	// 保存与节点v1相连的边
		edgeOfV[v2].push_back(eID);
	}	
	```


<br><br>

##	注意

*	不要把所有逻辑都混在在输入输出上
*	先读取输入
*	接着对输入进行过滤，得到midList
*	在得到ansList
*	然后输出
