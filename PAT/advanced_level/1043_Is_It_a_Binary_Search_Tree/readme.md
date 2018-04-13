*   生成一棵BST

	```cpp
	void insertBST(Node * & root, int val){
		if( NULL == root){
			root = new Node(val);
			return;
		}
		if( val < root->val ){
			insertBST(root->lchild);
		}else{
			insertBST(root->rchild);
		}
	}
	```

	使用上述方法，则一个输入序列唯一确定一棵树。

*	生成BST后，分别存储先序和镜面先序遍历序列，然后与题目的输入序列进行比较，即可得出答案