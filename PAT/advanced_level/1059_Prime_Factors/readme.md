### 尝试

1.  输入是正整数，说明0可以排除，特殊情况应该有输入为1的case

    ps: case3, 2分

2.  输入的n本身可能就是一个素数，那么输出 n=n

    ps: case4, 2分
    
3.  输入的n，只有一种素因子

### 完整

1.  核心代码

    ```cpp
    int upperBound = (int)sqrt(n);
    for( int i=0; i<cntPrime && primeList[i]<=upperBound ; ++i ){
    	int p = primeList[i];
    	if( n % p == 0 ){       //  这里不能直接上while(), 否则diffFac会出错
    		facList[diffFac].val = p;
    		facList[diffFac].cnt = 0;
    		while( n % p == 0){
    			n = n / p;
    			facList[diffFac].cnt++;
    		}
    		++diffFac;         	// n可以分解成diffFac种不同的质因子
    	}
    	if( n == 1 ){
    		break;
    	}
    }
    
    if( n != 1 ){
    	facList[diffFac].val = n;
    	facList[diffFac].cnt = 1;
    	++diffFac;
    }
    ```


### 不用担心内存，放心大胆地用

*   先用筛表法得到indexList[], indexList[i]==true 的i是素数

*   然后把i全都存到primeList[], 并记录总数