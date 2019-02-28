中序 + 层序 造树的模板

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
	// 
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
