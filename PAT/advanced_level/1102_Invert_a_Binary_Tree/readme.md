1.  二叉树的结构

    ```cpp
    struct Node{
		int parent, lchild, rchild;				// parent 用于寻找根结点，根结点的 parent 为 -1
		Node(){
			parent = lchild = rchild = -1;
		}
	};
	Node node[MAXSIZE];
    ```
    
    
2.	父子对应
    
	```
	for( int i = 0; i < n; ++i ){
		cin>>c1>>c2;
		if( isdigit(c1) ){
			node[i].lchild = c1 - '0';
			node[c1 - '0'].parent = i;
		}
		if( isdigit(c2) ){
			node[i].rchild = c2 - '0';
			node[c2 - '0'].parent = i;
		}
	}
    ```

2.  左右反转（后序LRN遍历，从叶节点开始反转）

    ```cpp
	/*	反转二叉树
		先反转根结点的左子树，再反转右子树
		然后反转根结点的左右孩子
	*/
	void invertTree(int root){
		if( root != -1 ){
			invertTree(node[root].lchild);
			invertTree(node[root].rchild);
			swap( node[root].lchild, node[root].rchild );
		}
	}
    ```

3.  层序，中序输出

4.  同类题目(PAT_A)

	1020 Tree Traversals
	1086 Tree Traversals Again
	
	1099. Build A Binary Search Tree
	1064 Complete Binary Search Tree
	1110. Complete Binary Tree
	
	1123. Is It a Complete AVL Tree
	1066 Root of AVL Tree
	
	
	1102. Invert a Binary Tree 
	
	1094. The Largest Generation
	
	1004. Counting Leaves

