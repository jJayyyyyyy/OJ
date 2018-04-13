根据结果得出的结论：第2条链中，一旦出现第一条链已经访问过的node，那么后面的都是公用的结点，而不会再次分叉。

```cpp
p = a2;
while( p != -1 ){
	if( nodelist[p].marked == true ){
		break;
	}else{
		p = nodelist[p].mNext;
	}
}
```

所以不要想太多太复杂(如何处理再分叉)