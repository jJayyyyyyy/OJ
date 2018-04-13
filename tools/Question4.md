##	树

*	AVL模板

    ```cpp
    #include <algorithm>
    
    struct Node{
    	Node *lchild=NULL, *rchild=NULL;
    	int val, height=1;
    	Node(int _val){
    		val = _val;
    	}
    };
    
    int getHeight(Node * root){
    	if( root == NULL ){
    		return 0;
    	}else{
    		return root->height;
    	}
    }
    
    void updateHeight(Node * root){
    	int lH = getHeight(root->lchild);
    	int rH = getHeight(root->rchild);
    	root->height = max(lH, rH) + 1;
    }
    
    int getBalanceFactor(Node * root){
    	int lH = getHeight(root->lchild);
    	int rH = getHeight(root->rchild);
    	return lH - rH;
    }
    
    void leftRotate(Node * & root){
    	Node * tmp = root->rchild;
    	root->rchild = tmp->lchild;
    	tmp->lchild = root;
    	updateHeight(root);
    	updateHeight(tmp);
    	root = tmp;
    }
    
    void rightRotate(Node * & root){
    	Node * tmp = root->lchild;
    	root->lchild = tmp->rchild;
    	tmp->rchild = root;
    	updateHeight(root);
    	updateHeight(tmp);
    	root = tmp;
    }
    
    void insertVAL(Node * & root, int val){
    	if( NULL == root ){
    		root = new Node(val);
    		return;
    	}
    
    	if( val < root->val ){
    		insertVAL(root->lchild, val);
    		updateHeight(root);
    		if( 2 == getBalanceFactor(root) ){
    			if( 1 == getBalanceFactor(root->lchild) ){
    				rightRotate(root);
    			}else{
    				leftRotate(root->lchild);
    				rightRotate(root);
    			}
    		}
    	}else{
    		insertVAL(root->rchild, val);
    		updateHeight(root);
    		if( -2 == getBalanceFactor(root) ){
    			if( -1 == getBalanceFactor(root->rchild) ){
    				leftRotate(root);
    			}else{
    				rightRotate(root->rchild);
    				leftRotate(root);
    			}
    		}
    	}
    }
    ```

*   堆

##	图

*	最短路径`Floyd`

    ```cpp
    void Floyd(){
    	for( int k = 0; k < n; k++ ){
    		for( int i = 0; i < n; i++ ){
    			for( int j = 0; j < n; j++ ){
    				if( dist[i][k] != INF && dist[k][j] != INF ){
    					if( dist[i][k] + dist[k][j] < dist[i][j] ){
    						dist[i][j] = dist[i][k] + dist[k][j];
    					}
    				}
    			}
    		}
    	}
    }
    ```    

*	最短路径`Dijkstra`

    ```cpp
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #define MAXSIZE 504
    #define INF 0x3fffffff
    using namespace std;
    
    int n, m, src, dest;
    bool vis[MAXSIZE] = {false};
    int G[MAXSIZE][MAXSIZE]
    int dist[MAXSIZE]
    vector<int> pre[MAXSIZE], tmpPath, ansPath;
    
    int cost2[MAXSIZE][MAXSIZE];
    int teamList[MAXSIZE];
    int maxTeam = 0, cntPath = 0;
    
    void init(){
    	fill(G[0], G[0] + MAXSIZE*MAXSIZE, INF);
    	fill(dist, dist + MAXSIZE, INF);
    }
    
    void Dijkstra(){
    	dist[src] = 0;
    	while( vis[dest] == false ){
    		int mid = -1;
    		int minDist = INF;
    		for( int i = 0; i < n; i++ ){
    			if( vis[i] == false && dist[i] < minDist ){
    				mid = i;
    				minDist = dist[i];
    			}
    		}
    		if( mid == -1 ){
    			return;
    		}
    
    		vis[mid] = true;
    		for( int i = 0; i < n; i++ ){
    			if( vis[i] == false && G[mid][i] != INF ){
    				if( dist[mid] + G[mid][i] < dist[i] ){
    					dist[i] = dist[mid] + G[mid][i];
    					pre[i].clear();
    					pre[i].push_back(mid);
    				}else if( dist[mid] + G[mid][i] == dist[i] ){
    					pre[i].push_back(mid);
    				}
    			}
    		}
    	}
    }
    
    void getMaxTeam(){
    	int tmpTeam = 0;
    	for( int i = tmpPath.size()-1; i >= 0; i-- ){
    		int now = tmpPath[i];
    		tmpTeam += teamList[now];
    	}
    	if( tmpTeam > maxTeam ){
    		maxTeam = tmpTeam;
    		ansPath = tmpPath;
    	}
    }
    
    void calCost(){
    	int tmpCost = 0;
    	for( int i = tmpPath.size()-1; i > 0; i-- ){
    		int now = tmpPath[i];
    		int next = tmpPath[i-1];
    		tmpCost += cost[now][next];
    	}
    	if( tmpCost < minCost ){
    		minCost = tmpCost;
    		ansPath = tmpPath;
    	}
    }
    
    void DFS(int v){
    	if( v == src ){
    		tmpPath.push_back(v);
    		calCost();
    		cntPath++;
    		tmpPath.pop_back();
    		return;
    	}
    
    	tmpPath.push_back(v);
    	for( int i = 0; i < pre[v].size(); i++ ){
    		DFS(pre[v][i]);
    	}
    	tmpPath.pop_back();
    }
    
    int main(){
    	ios::sync_with_stdio(false);
    	cin.tie(0);
    
    	init();
    	return 0;
    }
    ```

    

##  并查集

```
#include <iostream>
#define MAXSIZE 10004
using namespace std;

bool vis[MAXSIZE] = {false};
int father[MAXSIZE];
int treeList[MAXSIZE] = {0};

void init(){
	for( int i = 0; i < MAXSIZE; i++ ){
		father[i] = i;
	}
}

int findFather(int x){
	while( x != father[x] ){
		x = father[x];
	}
	return x;
}

void Union(int a, int b){
	int fa1 = findFather(a);
	int fa2 = findFather(b);
	if( fa1 < fa2 ){
		father[fa2] = fa1;
	}else{
		father[fa1] = fa2;
	}
}

// 并查集，看上去就像是森林，一个集合就是一棵树
// 统计有几棵树
void cntTreesAndBirds(){
	int maxBirdID = 0;   // ~maxID
	for( int i = 1; i < MAXSIZE; ++i ){
		if( vis[i] == true ){
			maxBirdID = i;           // 更新maxID
			int rootID = findFather(i);
			treeList[rootID]++;     // treeList[rootID] 的值表示这个区块里面有多少个结点
		}
	}
	int cntTree = 0;
	for( int i = 0; i < MAXSIZE; ++i ){
		if( treeList[i] > 0 ){
			cntTree++;              // treeList[i] 不为0，说明这是一个区块，i标识了该区块，即rootID
		}
	}
	cout<<cntTree<<' '<<maxBirdID<<'\n';
}

void isSameTree(){
	int q, id1, id2;
	cin>>q;
	for( int i = 0; i < q; ++i ){
		cin>>id1>>id2;
		if( findFather(id1) == findFather(id2) ){   // 千万注意，判断是否在同一区块，要用findFather(), 而不是father[]是否相等（除非进行了路径优化）
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	int n, k, id1, id2;
	cin>>n;
	for( int i = 0; i < n; ++i ){
		cin>>k;
		if( k > 0 ){
			cin>>id1;
			vis[id1] = true;
			for( int j = 1; j < k; j++ ){
				cin>>id2;
				vis[id2] = true;

				// merge, union
				Union(id1, id2);
			}
		}
	}


	cntTreesAndBirds();
	isSameTree();
	return 0;
}
```


##	注意

*	不要把所有逻辑都混在在输入输出上
*	先读取输入
*	接着对输入进行过滤，得到midList
*	在得到ansList
*	然后输出
