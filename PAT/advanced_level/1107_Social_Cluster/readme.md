union find set, 并查集, disjoint set

##	关键点

*	关键0，初始化！

*	关键1，在每次输入时进行 Union()，合并区块。并标记 vis[i] 为 true

*	关键2，计算区块数量，以及各种maxID

*   剩下的就是记模板

*   PAT_A参考题目
    
    1.  输入完成后，结构不变：1021, 1107, 1114, 1118

##	逻辑

*	下面5行是本题关键代码，在输入时进行Union，构造并查集，其他都是模板

	```cpp
	if( hobbyList[h] == EMPTY ){
		hobbyList[h] = id;
	}
	int hobbyOwnerID = findFather(hobbyList[h]);
	Union( id, hobbyOwnerID );
	```

