1.  同类题目

    *   1074
    
2.  注意

    *   结构体
    
        ```cpp
        struct Node{
        	int mAddr=-2, mVal, mNext;
        	bool mMarked=false;
        	int set(int addr, int val, int next){
        		mAddr = addr;
        		mVal = val;
        		mNext = next;
        		return 0;
        	}
        };
        ```
        
        方便排序
        
        ```cpp
        int cmp(Node a, Node b){
            return a.mVal < b.mVal;
        }
        ```

    *   某些节点可能不在链表里面，注意剔除。方法有很多，这里用的方法是
    
        ```cpp
    	int cnt = 0;
    	int p = start;
    	while( p != -1 ){
    		tmpNode[p].mMarked = true;
    		nodeList[cnt++] = tmpNode[p];
    		p = tmpNode[p].mNext;
    	}
        ```
        
        其中tmpNode[]是原始输入列表，然后从起点开始遍历，能串起来的结点构成了nodeList[]，注意nodeList[]也可能为空
