1.	如果没有思路，可以考虑边界，试着拿点分数

	```cpp
	if( n == k ){
		cout<<n<<" = ";
		cout<<"1^"<<p;
		for( i=1; i<k; ++i ){
			cout<<" + "<<"1^"<<p;
		}
		cout<<'\n';
		return 0;
	}

	if( n > k ){
		int lowerTH = k - 1 + pow(2, p);
		// cout<<lowerTH<<'\n';
		if( n < lowerTH ){
			cout<<"Impossible\n";
			return 0;
		}	
	}
	```

	一共30分，这样可以拿4分
	
##	思路

1.	建立一个fac数组，里面的下标当做底数base，然后算出所有的base^p，上界是base^p <= n

2.	init一次性算好fac，以后可以重用，免得临时算增加时间开销

3.	从最大的底数 base 开始，从大到小，试探n 能由多少个fac[base]组成
