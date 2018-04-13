1.	同类题目

	1021, 1107, 1114, 1118

2.	使用并查集模板即可，这里数据估计比较简单，不使用路径压缩也能完成。

	关键点

	*	输入的时候，进行`vis[i] = true;`，以及`Union(id1, id2);`
	
	*	统计区块，以及maxID
	
    ```
    // 统计区块，以及maxID
    void cntTreesAndBirds(){
    	int cntBirds = 0;	// ~maxID
    	for( int i = 1; i < MAXSIZE; ++i ){
    		if( vis[i] == true ){
    			cntBirds = i;			// 更新maxID
    			int rootID = findFather(i);
    			treeList[rootID]++;		// treeList[rootID] 的值表示这个区块里面有多少个结点
    		}
    	}
    	int cntTree = 0;
    	for( int i = 0; i < MAXSIZE; ++i ){
    		if( treeList[i] > 0 ){
    			cntTree++;				// treeList[i] 不为0，说明这是一个区块，i标识了该区块，即rootID
    		}
    	}
    	cout<<cntTree<<' '<<cntBirds<<'\n';
    }
    ```

	*	千万注意，判断是否在同一区块，要用findFather(), 而不是father[]是否相等（除非进行了路径压缩）