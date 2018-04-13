1.  BFS，（太深了，用DFS会爆栈）

2.  三维坐标与晴神宝典略有不同

    ```cpp
    int pixel[ZSIZE][XSIZE][YSIZE];     // 内存够用，尽量选int，比bool要快一些
    
    for( int z=0; z < slice; ++z ){
		for( int x=0; x<m; ++x){
			for(int y=0; y<n; ++y){
				cin>>pixel[z][x][y];    // 坐标形式要注意，首先是第z层，然后是该层内的坐标[row][col]，即[x][y]
			}
		}
	}
    ```

    根据OS的知识，这样的数组坐标设计，也有更好的局部性，可以有更好的性能

3.  judge

    ```cpp
    bool judge(int z, int x, int y){
    	if( z >= slice || z < 0 || x >= m || x < 0 || y >= n || y < 0 ){
    		return false;
    	}
    	if( pixel[z][x][y] == 0 || inq[z][x][y] == true ){
    		return false;
    	}
    	return true;
    }
    ```

4.  BFS

    ```cpp
    int BFS(int z, int x, int y){
    	int volume = 0;
    	queue<Node> q;
    	Node node(z, x, y);
    	q.push(node);
    	inq[z][x][y] = true;
    
    	while( q.size() ){
    		Node now = q.front();
    		q.pop();
    		++volume;
    		for( int i=0; i<6; ++i ){
    			int newZ = now.z + incZ[i];
    			int newX = now.x + incX[i];
    			int newY = now.y + incY[i];
    			if( judge(newZ, newX, newY) ){
    				Node n(newZ, newX, newY);
    				q.push(n);
    				inq[newZ][newX][newY] = true;
    			}
    		}
    	}
    
    	if( volume >= th ){
    		return volume;
    	}else{
    		return 0;
    	}
    }
    ```


4.  再写几次，熟悉感觉