### 如何赚分

1.  首先要确定表长，也就是要会筛表法求素数

    ```cpp
    ##include <cmath>
    #define MAXSIZE 10009
    bool primeList[MAXSIZE] = {false, false, true};
    
    int getPrimeList(){
    	for( int i=3; i<MAXSIZE; i+=2 ){
    		primeList[i] = true;
    		primeList[i+1] = false;
    	}
    	int upperBound = (int)sqrt(MAXSIZE);
    	for( int i=3; i<=upperBound; i+=2 ){
    		if( true == primeList[i] ){
    			for( int j=i+i; j<MAXSIZE; j+=i ){
    				primeList[j] = false;
    			}
    		}
    	}
    	return 0;
    }
    ```

2.  假设没有冲突，试一试

    ```cpp
    int main(){
    	getPrimeList();
    	int size, n, a, i;
    	cin>>size>>n;
    
    	while( false == primeList[size] ){
    		++size;
    	}
    
    	for( i=0; i<n; ++i ){
    		cin>>a;
    		int key = a % size;
    		if( false == hashTable[key] ){
    			hashTable[key] = true;
    			output(key, i);
    		}
    	}
    
    	return 0;
    }
    ```

    你猜怎么着，25分里面可以拿8分~
    
3.  假设，就算冲突了，也能用Quadratic probing全部插入。

    这里，Quadratic probing的意思是正向二次方探测法，即
    
    ```
    if Hash(a) 冲突:
        for step in range(1, TSize):
            a ---> (a + step*step)
            检测 Hash(a) 是否冲突
    ```
    
    转换成代码，就是
    
    ```cpp
    if( true == hashTable[key] ){
        int step;
        for( step = 1; step < TSize; ++step ){
            key = (a + step*step) % TSize;
            if( false == hashTable[key] ){
                // ok we find the right position
                hashTable[key] = true;
                output(key);
                break;
            }
        }
        // 如果不处理题目中impossible的情况，那么可以拿13分
        // 加上下面这段代码，就可以拿剩下的12分
        
        if( step >= TSize ){
            cout<<"-";
        }
    }
    ```

    至于为啥是step的范围是range(1, TSize)，简单来说，就是
    
    ```
    step >= TSize时, 
    由于 key = key = (a + step*step) % TSize
    a + step * step 多出来的部分可以被TSize给模掉，
    又回到 1 <= step < TSize 的情况
    ```
    
    具体证明请参考晴神宝典