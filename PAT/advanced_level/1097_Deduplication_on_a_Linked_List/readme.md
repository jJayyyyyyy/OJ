0.  建立`bool marked[MAXSIZE] = {false};`用于记录元素绝对值是否出现过。这是一个hash表

1.  输入完成之后，从起点开始遍历链表

2.  根据marked[]，将首次出现的结点加入ansList1[]，重复的结点加入ansList2[]

    ```cpp
    while( p != -1 ){
		val = tmpList[p].mVal;
		absVal = abs(val);

		if( false == marked[absVal] ){
			marked[absVal] = true;
			ansList1[cnt1].mAddr = p;
			ansList1[cnt1].mVal = val;
			++cnt1;
		}else{
			ansList2[cnt2].mAddr = p;
			ansList2[cnt2].mVal = val;
			++cnt2;
		}
		p = tmpList[p].mNext;;
	}
    ```

*   内存换时间，不用心疼内存。