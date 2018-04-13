1.  BST中序遍历可以得到递增序列

2.  CBT用数组表示，进行中序遍历，同时依次填入递增节点，即可得到CBST

	CBT的根是i，那么左子树就是`2*i`，右子树就是`2*i + 1`，由此可进行中序遍历，边界是 `root <= n`

	```cpp
	// CBT inOrderTraverse
	void inOrder(int root){
		if( root <= n ){
			inOrder( root*2 );		// lchild
			CBT[root] = nodeList[ix++];
			inOrder( root*2 + 1 );	// rchild
		}
	}
	```

3.	CBT的层序遍历，即对数组进行 [1, n] 的遍历，
