1.  筛表法建立素数标

    ```cpp
    #define MAXSIZE 10005
    #include <cmath>
    
    int primeList[MAXSIZE] = {0, 0, 1};
    int upperBound = (int)sqrt(MAXSIZE);
    int i, j;
    
    for( i=3; i<MAXSIZE; i+=2 ){
        primeList[i] = 1;
        primeList[i+1] = 0;
    }
    
    for( i=3; i<upperBound; i+=2 ){
        if( 1 == primeList[i] ){
            for( j=i+i; j<MAXSIZE; j+=i ){
                primeList[j] = 0;
            }
        }
    }
    ```

2.  如果query是没有参赛的ID，那不管问几次，回答都是`Are you kidding?`，而不是`Checked`

3.  根据ID建立索引，空间换时间。
