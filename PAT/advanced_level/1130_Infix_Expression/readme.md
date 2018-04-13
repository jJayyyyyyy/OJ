##  思路

*   解法很多，下面的思路比较直观，参考链接[坚不萌的CSDN](http://blog.csdn.net/shepherd2010/article/details/72862254)

    >   题意不难。中序遍历就行了，不过难点在于括号的输出。
    >
    >   递归的时候，加个判断条件。
    >
    >   只要当前遍历的不是根结点且左右不全空，就输出括号。
    
*   对上面第三行的解释：
    
    ```cpp
    // 此处解释说明使用了链表的形式，结合题目则要改成静态写法
    bool hasParenthsis = false;
    if( root != ROOT ){     // root是当前子树的根节点，ROOT是整棵树的根节点
        if( root->lchild != NULL || root->rchild != NULL ){
            hasParenthsis = true;
        }
    }
    ```
    
*   中序遍历

    ```cpp
    void inOrder(int root){
    	if( root != -1 ){
    		bool hasParenthsis = false;
    		if( root != ROOT ){       // 最外层的表达式不需要括号
    			if( node[root].lchild != -1 || node[root].rchild != -1 ){   // 如果不是叶节点，就要加括号
    				hasParenthsis = true;
    			}
    		}
    
    		// (lVal + op + rVal)的结构
    		if( true == hasParenthsis ){
    			expression += "(";
    		}
    		inOrder(node[root].lchild);
    		expression += node[root].val;
    		inOrder(node[root].rchild);
    		if( true == hasParenthsis ){
    			expression += ")";
    		}
    	}
    }
    ```

*   寻找ROOT

    遍历数组，parent为-1的节点，就是整棵树的根。按照要求，最外层的表达式不加括号

##  其他

*   未充分理解的知识点：前缀表达式、中缀表达式、后缀表达式，实现与应用。后序再补充。