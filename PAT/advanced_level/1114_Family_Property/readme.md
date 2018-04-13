union find set, 并查集, disjoint set

*   关键是在每次输入时进行Union，合并区块

*   剩下的就是记模板

*   PAT_A参考题目
    
    1.  输入完成后，结构不变：1021, 1107, 1114, 1118
    
##  思路与代码解析

1.  切记初始化

2.  本题关键点，边输入，边构造并查集

    把输入各种的id, fID, mID, cID，归类到各自的家族
    
    统计区块数目，以及maxFamilyID
    
    ```
    for( i = 0; i < n; ++i ){
		cin>>id>>fID>>mID>>k;
		info[i].set(id, fID, mID, k);
		
		marked[id] = true;
		if( fID != -1 ){
			marked[fID] = true;
			Union(fID, id);
		}
		if( mID != -1 ){
			marked[mID] = true;
			Union(mID, id);
		}

		for( j = 0; j < k; ++j ){
			cin>>cID;
			info[i].chID[j] = cID;
			marked[cID] = true;
			Union(cID, id);
		}
	}
    ```

3.  统计各个家族的人数，资产情况。把数据全都放到family[repID]

4.  并查集的模板（含结构体的模板）

    ```cpp
    struct Family{
    	int rootID;		// 代表家族的成员的编号
    	int people;		// 家族人数
    	Family(){
    		rootID = -1;
    		people = 0;
    	}
    };
    
    Family family[MAXSIZE];
    int father[MAXSIZE];
    bool vis[MAXSIZE] = {false};
    
    // 省略的代码，请参考cpp文件
    /* ... */
    
    // 统计区块block，以及maxFamilyID
    void cntBlockAndMaxID(int & block, int & maxFamilyID){
    	for( int i = 0; i < MAXSIZE; ++i ){
    		if( vis[i] == true ){
    		    // maxID在这里统计，不过本题用不到
    			int rootID = findFather(i);
    			family[rootID].rootID = rootID;
    			family[rootID].people++;
    		}
    	}
    
    	block = maxFamilyID = 0;
    	for( int i = 0; i < MAXSIZE; ++i ){
    		int people = family[i].people;
    		if( people > 0 ){
    			// 家族成员数肯定为正，否则家族为空
    			// 这里的i可以理解为某个家族的rootID
    			block++;
    			maxFamilyID = i;
    		}
    	}
    }
    ```