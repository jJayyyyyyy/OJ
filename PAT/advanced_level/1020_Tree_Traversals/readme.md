*   1020，后序+中序，构造二叉树，层序输出

    同类题目：1020, 1086, 1127

*   模板

    ```cpp
    struct Node{
    	int val=0;
    	Node *lchild=NULL, *rchild=NULL;
    	Node(int _val){
    		val = _val;
    	}
    };
    
    int inTrav[MAXSIZE], postTrav[MAXSIZE];
    
    // 1020, 后序+中序，造树
    Node * postInCreate(int postL, int postR, int inL, int inR){
    	if( postL > postR ){
    		return NULL;
    	}
    	int rootVal = postTrav[postR];
    	Node * root = new Node(rootVal);
    
    	int mid;
    	for( mid = inL; mid <= inR; ++mid ){
    		if( inTrav[mid] == rootVal ){
    			break;
    		}
    	}
    	int numLeft = mid - inL;
    	root->lchild = postInCreate(postL, postL+numLeft-1, inL, mid-1);
    	root->rchild = postInCreate(postL+numLeft, postR-1, mid+1, inR);
    	return root;
    }
    ```
