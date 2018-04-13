*   注意，在在输入数量上，本题和同类题目略有区别。同类题目列表请参考[1102的readme](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1102_Invert_a_Binary_Tree)，以及[DS---Tree](https://github.com/jJayyyyyyy/cs/tree/master/data%20structure/tree)

*   20170806更新，判断是否为完全二叉树，更直观好记的写法，参考王道P131, App7 + [data structure](https://github.com/jJayyyyyyy/cs/tree/master/data%20structure/tree)

    ```cpp
    // 静态数组
    int isCBTLevelTrav(int root){
    	if( root != NONE ){
    		queue<int> q;
    		q.push(root);
    		while( q.size() > 0 ){
    			int node = q.front();
    			// visit(parent)
    			q.pop();
    			if( node != NONE ){
    				q.push(nodeList[node].lchild);
    				q.push(nodeList[node].rchild);
    			}else{
    				while( q.size() > 0 ){
    					int p = q.front();
    					if( p != NONE ){
    						return 0;
    						// break;
    					}
    					q.pop();
    				}
    			}
    		}
    	}
    	return 1;
    }
    
    // 二叉链表
    int isCBTLevelTrav(Node * root){
    	if( root != NULL ){
    		queue<Node *> q;
    		q.push(root);
    		while( q.size() > 0 ){
    			Node * node = q.front();
    			// visit(node);
    			q.pop();
    			if( node != NULL ){
    				q.push(node->lchild);
    				q.push(node->rchild);
    			}else{
    				while( q.size() > 0){
    					Node * p = q.front();
    					if( p != NULL ){
    						return 0;
    						// break;
    					}
    					q.pop();
    				}
    			}
    		}
    	}
    	return 1;
    }
    ```

*   20170810更新，更改内循环中pop的顺序，先访问p，再pop，以适用题目1123