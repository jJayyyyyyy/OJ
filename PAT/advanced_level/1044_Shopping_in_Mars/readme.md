1.  `sum[]`

    *   令 `sum[i]` 表示 `a[1]` 到 `a[j]` 的和，即 sum[i] = a[1] + a[2] + ... + a[i]
    
    *   则 `a[i]` 到 `a[j]` 的和可以表示为 `sum[j] - sum[i - 1]`

    *   由于 `a[i]` 均为正数，因此 `sum[i]` 是严格递增数列。于是我们可以遍历起点，用二分法查找终点，即
    
        在 [ sum[i], sum[n] ] 中查找 sum[i] + S 


2.  代码描述
    
    ```cpp
    for( i = 1; i <= n; ++i ){
		top = sum[i - 1] + S;
		j = lower_bound(sum + i, sum + n + 1, top) - sum;
		if( sum[j] - sum[i - 1] == S ){
			nearS = S;
			break;
		}else if( j <= n && (sum[j] - sum[i-1] < nearS ) ){
			nearS = sum[j] - sum[i - 1];
		}
	}

	for( i = 1; i <= n; ++i ){
		top = sum[i - 1] + nearS;
		j = lower_bound(sum + i, sum + n + 1, top) - sum;
		if( sum[j] - sum[i - 1] == nearS ){
			cout<<i<<'-'<<j<<'\n';
		}
	}    
    ```
