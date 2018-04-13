1.	Longest Common Subsequences, 最长公共子序列

	总体最优--->局部最优

2.	边界（目前理解为初始化）

	```cpp
	for( i = 0; i <= len1; ++i ){
		dp[i][0] = 0;
	}
	for( j = 0; j <= len2; ++j ){
		dp[0][j] = 0;
	}
	```

3.1	普通模板（不重复）

	```cpp
	// 注意从1开始
	for( i = 1; i <= len1; ++i ){
		for( j = 1; j <= len2; ++j ){
			if( s1[i] == s2[j] ){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	```
	
3.2	本题模板（允许重复）

	```cpp
	for( i = 1; i <= len1; ++i ){
		for( j = 1; j <= len2; ++j ){
			int tmpMAX = max(dp[i - 1][j], dp[i][j - 1]);
			if( s1[i] == s2[j] ){
				dp[i][j] = tmpMAX + 1;
			}else{
				dp[i][j] = tmpMAX;
			}
		}
	}
	```
