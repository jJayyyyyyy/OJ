*   1086，前序+中序，造树，后序输出

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
    
    int preTrav[MAXSIZE], inTrav[MAXSIZE];
    
    // 1086, 先序+中序，造树
    Node * preInCreate(int preL, int preR, int inL, int inR){
    	if( preL > preR ){
    		return NULL;
    	}
    	int val = pre[preL];
    	Node * root = new Node(val);
    
    	int mid;
    	for( mid = inL; mid <= inR; ++mid ){
    		if( in[mid] == val ){
    			break;
    		}
    	}
    	int numLeft = mid - inL;
    	root->lchild = preInCreate(preL+1, preL+numLeft, inL, mid-1);
    	root->rchild = preInCreate(preL+numLeft+1, preR, mid+1, inR);
    	return root;
    }
    ```
    
*   相比1020，本题多了一个关键点，就是前序遍历的非递归做法。

    前序是NLR，此时的push相当于L，pop相当于N，这样就可以获得pre[]和in[]了

    ```cpp
    // 如果要实现非递归的NLR前序遍历，可以用这个模板
    void preOrder_nr(Node * root){
    	stack<Node *> s;
    	Node *p = root;
    	while( p != NULL || s.size() > 0 ){
    		// 一路往左
    		if( p != NULL ){
    			// visit(p);
    			s.push(p->rchild);
    			p = p->lchild;
    		}else{  // 到左端尽头了，也就是把NL结束了，下面进行R，R在栈里
    			p = s.top();
    			s.pop();
    		}
    	}
    }
    ```