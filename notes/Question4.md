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

*	堆

	<br>

##	图

*	最短路径 `Floyd`

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

*	最短路径 `Dijkstra`

	```cpp
	#include <iostream>
	#include <algorithm>
	#include <vector>
	#define MAXSIZE 504
	#define INF 0x3fffffff
	using namespace std;

	int n, m, src, dest;
	bool vis[MAXSIZE] = {false};
	int G[MAXSIZE][MAXSIZE];
	int dist[MAXSIZE];
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
				// 从未访问结点集合中选出结点 mid , 使 dist[mid] 最小
				if( vis[i] == false && dist[i] < minDist ){
					mid = i;
					minDist = dist[i];
				}
			}
			if( mid == -1 ){
				return;
			}

			// 设置 mid 为已访问结点
			// 以 mid 为中间结点, 更新 mid 能够到达的结点的 dist[]
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

*	最短路径 `Bellman-Ford`

	```cpp
	/*
	只考虑最短路径唯一的情况
	*/
	#include <iostream>
	#include <vector>
	#define INF 0x3fffffff
	using namespace std;
	
	struct Node{
		int vertex, distance;
		Node(int v, int d){
			vertex = v;
			distance = d;
		}
	};
	
	class BellmanFord{
	public:
		int n;
		vector<vector<Node> > graph;
		vector<vector<int> > pre;
		vector<int> dist, ansPath;
	
		BellmanFord(){
		}
	
		BellmanFord(int numVertex){
			n = numVertex;
			graph.resize(n);
			dist.resize(n, INF);
		}
	
		void init(){
			graph.resize(n);
			pre.resize(n);
			dist.resize(n, INF);
		}
	
		// get shortest path d[] using BF algorithm
		void doBF(int src){
			fill(dist.begin(), dist.end(), INF);
			dist[src] = 0;
			// iteration = |V| - 1 = n - 1
			// 结点编号为 [0, n-1]
			for( int i = 0; i < n - 1; i++ ){
				// 把每个结点当作中间结点 mid, 尝试更新 mid 能够到达的结点的 dist[]
				for( int mid = 0; mid < n; mid++ ){
					for( Node node : graph[mid] ){
						int nextV = node.vertex;
						int distance = node.distance;
						if( dist[mid] + distance < dist[nextV] ){
							dist[nextV] = dist[mid] + distance;
						}
					}
				}
			}
		}
	
		// @return: false is good, true is bad
		bool hasNegativeCircle(){
			for( int mid = 0; mid < n; mid++ ){
				for( Node node : graph[mid] ){
					int nextV = node.vertex;
					int distance = node.distance;
					if( dist[mid] + distance < dist[nextV] ){
						return true;
					}else if( dist[mid] + distance == dist[nextV] ){
						pre[nextV].clear();
						pre[nextV].push_back(mid);
					}
				}
			}
			return false;
		}
	
		void dfs(int src, int v){
			if( v == src ){
				ansPath.push_back(v);
				return;
			}
	
			for( int preV : pre[v] ){
				dfs(src, preV);
				ansPath.push_back(v);
			}
		}
	
		void getPath(int src, int dest){
			ansPath.clear();
			dfs(src, dest);
			if( ansPath.size() > 0 ){
				cout<<ansPath[0];
				for( int i = 1; i < ansPath.size(); i++ ){
					cout<<"->"<<ansPath[i];
				}
			}
		}
	
		void getPathAndDistance(int src, int dest){
			// cout<<"Shortest distance from src "<<src<<" to each node is as below:\n";
			cout<<"Path from "<<src<<" to "<<dest<<'\n';
			int distance = dist[dest];
			if( distance != INF ){
				getPath(src, dest);
				cout<<"\ndistance: "<<distance<<"\n\n";
			}else{
				cout<<"No Path";
				cout<<"\ndistance: INF\n\n";
			}
		}
	
		void test(){
			n = 6;
			init();
	
			graph[0].push_back(Node(2, 100));
			graph[0].push_back(Node(3, 30));
			graph[0].push_back(Node(4, 10));
	
			graph[1].push_back(Node(4, 5));
	
			graph[3].push_back(Node(2, 60));
			graph[3].push_back(Node(5, 20));
	
			graph[4].push_back(Node(5, 50));
	
			graph[5].push_back(Node(2, 10));
	
			int src = 0;
			doBF(src);
	
			if( hasNegativeCircle() == false ){
				for( int dest = 0; dest < n; dest++ ){
					getPathAndDistance(src, dest);
				}
			}else{
				cout<<"there is a negative circle\n";
			}
		}
	};
	
	int main(){
		cout<<"Bellman-Ford algorithm\n-----------------------\n";
		BellmanFord bf;
		bf.test();
		return 0;
	}
	```

	<br>

##	并查集

*	模板

	```cpp
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
		int maxBirdID = 0;			// maxID
		for( int i = 1; i < MAXSIZE; ++i ){
			if( vis[i] == true ){
				maxBirdID = i;		// 更新maxID
				int rootID = findFather(i);
				treeList[rootID]++;	// treeList[rootID] 的值表示这个区块里面有多少个结点
			}
		}
		int cntTree = 0;
		for( int i = 0; i < MAXSIZE; ++i ){
			if( treeList[i] > 0 ){
				cntTree++;		// treeList[i] 不为0，说明这是一个区块，i标识了该区块，即rootID
			}
		}
		cout<<cntTree<<' '<<maxBirdID<<'\n';
	}

	void isSameTree(){
		int q, id1, id2;
		cin>>q;
		for( int i = 0; i < q; ++i ){
			cin>>id1>>id2;
			// 千万注意，判断是否在同一区块，要用findFather(), 而不是father[]是否相等（除非进行了路径优化）
			if( findFather(id1) == findFather(id2) ){
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

	<br>

##	LCA

*	模板

	```cpp
	#include <iostream>
	#define MAXSIZE 10004
	using namespace std;

	// i = val_to_index[val] , 其中 i 是结点 val 在中序序列里的下标
	// 如果出现段错误则逐步增加数组容量
	int val_to_index[MAXSIZE] = {0};
	// s 用于判断某结点是否在树中
	bool s[MAXSIZE] = {false};
	int in[MAXSIZE], pre[MAXSIZE];
	// iu, iv 是 u, v 在中序序列里的下标
	int iu, iv;

	void in_pre_create_tree(int inL, int inR, int preL, int preR, int u, int v)
	{
		if( preL > preR )
		{
			return;
		}

		int rootval = pre[preL];			// 根结点的值
		int iroot = val_to_index[rootval];	// 根结点的下标
		int numLeft = iroot - inL;			// 左子树结点总数

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
			in_pre_create_tree(inL, iroot - 1, preL + 1, preL + numLeft, u, v);
		}
		else if( iroot < iu && iroot < iv )
		{
			// u 和 v 在 root 的右子树中, 去右子树找
			in_pre_create_tree(iroot + 1, inR, preL + numLeft + 1, preR, u, v);
		}
	}

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);

		int m, n;
		cin >> m >> n;

		int val;
		for( int i = 0; i < n; i++ )
		{
			cin >> val;
			in[i] = val;
			val_to_index[val] = i;
			s[val] = true;
		}

		for( int i = 0; i < n; i++ )
		{
			cin >> pre[i];
		}

		int u, v;
		for( int i = 0; i < m; i++ )
		{
			cin >> u >> v;
			bool findu = s[u];
			bool findv = s[v];
			if( findu == false && findv == false )
			{
				cout << "ERROR: " << u << " and " << v << " are not found.\n";
			}
			else if( findu == false )
			{
				cout << "ERROR: " << u << " is not found.\n";
			}
			else if( findv == false )
			{
				cout << "ERROR: " << v << " is not found.\n";
			}
			else
			{
				iu = val_to_index[u];		// iu 是 u 在中序序列里的下标
				iv = val_to_index[v];		// iv 是 v 在中序序列里的下标
				in_pre_create_tree(0, n - 1, 0, n - 1, u, v);
			}
		}

		return 0;
	}
	```

*	例题

	[PAT_A_1143](https://github.com/jJayyyyyyy/OJ/tree/master/PAT/advanced_level/1143_Lowest_Common_Ancestor), [PAT_A_1151](https://github.com/jJayyyyyyy/OJ/blob/master/PAT/advanced_level/1151_LCA_in_a_Binary_Tree/1151_LCA_in_a_Binary_Tree.cpp)
	
	[LeetCode, P235_Lowest_Common_Ancestor_of_a_BST](https://github.com/jJayyyyyyy/OJ/blob/master/LeetCode/201-300/P235_Lowest_Common_Ancestor_of_a_BST.cpp)

	[LeetCode, P236_Lowest_Common_Ancestor_of_a_Binary_Tree](https://github.com/jJayyyyyyy/OJ/blob/master/LeetCode/201-300/P236_Lowest_Common_Ancestor_of_a_Binary_Tree_*.cpp)

*	更简洁的方法(递归)

	```cpp
	// LeetCode 235, 236 都适用
	TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q){
		if( root == NULL || root == p || root == q ){
			return root;
		}
		TreeNode * left = lowestCommonAncestor(root->left, p, q);
		TreeNode * right = lowestCommonAncestor(root->right, p, q);
		if( left != NULL && right != NULL ){
			return root;
		}
		else{
			return left==NULL ? right : left;
		}
	}
	```

	<br>

##	注意

*	不要把所有逻辑都混在在输入输出上
*	先读取输入
*	接着对输入进行过滤，得到midList
*	在得到ansList
*	然后输出
