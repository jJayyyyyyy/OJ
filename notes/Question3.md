##	树

*	数据结构

	```cpp
	struct Node
	{
		int val, level;
		Node *lchild, *rchild;
		Node(int _val)
		{
			val = _val;
			level = 1;
			lchild = rchild = NULL;
		}
	}
	```

*	in_pre, 中序 + 前序 造树, , PAT_A_1086

	```cpp
	Node * in_pre(int inL, int inR, int preL, int preR)
	{
		if( preL > preR )
		{
			return NULL;
		}

		int rootval = pre[preL];
		Node * root = new Node(rootval);

		int iroot = val_to_index[rootval];
		int numLeft = iroot - inL;

		root->lchild = in_pre(inL, iroot - 1, preL + 1, preL + numLeft);
		root->rchild = in_pre(iroot + 1, inR, preL + numLeft + 1, preR);
		return root;
	}
	```

*	in_post, 中序 + 后序 造树, PAT_A_1020

	```cpp
	int val_to_index[MAXSIZE] = {0};
	int in[MAXSIZE], post[MAXSIZE];

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

	int main()
	{
		// ...
		for( int i = 0; i < n; i++ )
		{
			int val;
			cin >> val;
			in[i] = val;
			val_to_index[val] = i;
		}
		// ...
	}
	```

*	in_level, 中序 + 层序 造树

	参考试题: [浙大机试模拟赛-1005](https://logn.me/problem/1005)

	[题解: https://github.com/jJayyyyyyy/OJ/tree/master/%E6%B5%99%E5%A4%A7%E6%9C%BA%E8%AF%95%E6%A8%A1%E6%8B%9F%E8%B5%9B/1005](https://github.com/jJayyyyyyy/OJ/tree/master/%E6%B5%99%E5%A4%A7%E6%9C%BA%E8%AF%95%E6%A8%A1%E6%8B%9F%E8%B5%9B/1005)

	```cpp
	// i = val_to_index[val] , 其中 i 是结点 val 在中序序列里的下标
	int val_to_index[MAXSIZE] = {0};
	int in[MAXSIZE], level[MAXSIZE];

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

	int main()
	{
		// ...
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
			// 层序是自上而下的, 每一个节点 level[i] 依次是子树的根
			int valnode = level[i];
			int inode = val_to_index[valnode];

			in_level( root, valnode, inode );
			// valnode 是子树根结点的值, inode 是子树的根在 in 序列的位置
		}
		// ...
	}
	```

*	level_traverse, 层序遍历

	模板1

	```cpp
	void level_traverse(Node * root)
	{
		queue<Node *> q;
		q.push(root);
		while( q.size() != 0 )
		{
			Node * parent = q.front();
			q.pop();
			visit(parent);

			if( parent->lchild != NULL )
			{
				parent->lchild->level = parent->level + 1;
				q.push(parent->lchild);
			}
			if( parent->rchild != NULL )
			{
				parent->rchild->level = parent->level + 1;
				q.push(parent->rchild);
			}
		}
	}
	```

	模板2

	```cpp
	void level_traverse(Node * root)
	{
		queue<Node *> q;
		q.push(root);
		while( q.size() != 0 )
		{
			int len = q.size();
			for( int i = 0; i < len; i++ )
			{
				Node * parent = q.front();
				q.pop();
				visit(parent);
				if( parent->lchild != NULL )
				{
					q.push(parent->lchild);
				}
				if( parent->rchild != NULL )
				{
					q.push(parent->rchild);
				}
			}
		}
	}
	```

##	图

*	DFS

*	BFS

*	连通图

	```cpp
	void DFS(int now)
	{
		if( vis[now] == false )
		{
			vis[v] = true;
			for( int next : graph[now] )
			{
				DFS(next);
			}
		}
	}

	// 获得连通块的个数
	int cnt_block(int n)
	{
		int block = 0;
		for( int v = 1; v <= n; v++ )
		{
			if( vis[v] == false )
			{
				DFS(v);
				block++;
			}
		}
		return block;
	}
	```

*   边的遍历, PAT_A_1134

	```
	vector<int> edge_of_vertex[MAXSIZE];
	bool visited_edge[MAXSIZE];

	for( int eid = 0; eid < m; eid++ ){
		cin >> v1 >> v2;

		// 给每条边编号, [0, m-1]
		edge_of_vertex[v1].push_back(eid);	// 保存与节点 v1 相连的边
		edge_of_vertex[v2].push_back(eid);	// 保存与节点 v2 相连的边
	}	
	```

<br><br>

##	注意

*	不要把所有逻辑都混在在输入输出上
*	先读取输入
*	接着对输入进行过滤，得到 mid_list
*	在得到 ans_list
*	然后输出
