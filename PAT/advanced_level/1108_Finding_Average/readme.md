
##	分步走

1.	小数点的个数 <= 1

	`checkPointer()`

2.	去掉小数点后，都是数字 ( 第一位可以是负号 `-` )

	`checkDigit()`

3.	精度， 2位小数

	`checkAccu()`

4.	范围 [-1000, 1000]

	`checkRange()`

<br><br>

##	强大的 `stringstream` + `setprecision(2)`，可以完成分步走中的前3步

```cpp
/* 
** filter
** 1.2.34 ---> 1.20
** 1.c2b.34a ---> 1.00
*/
string str2num2str(string raw){
	stringstream ss1, ss2;
	double tmp;
	string filtered;

	ss1<<raw;
	ss1>>tmp;
	ss2<<fixed<<setprecision(2)<<tmp;
	ss2>>filtered;
	return filtered;
}

/* 
** valid pointer && digit && accuracy
*/
bool isValid(string raw){
	string filtered = str2num2str(raw);

	int len1 = raw.size();
	int len2 = filtered.size();
	bool valid = true;
	if( len1 == len2 ){
		for( int i = 0; i < len1; i++ ){
			if( raw[i] != filtered[i] ){
				valid = false;
			}
		}
	}else{
		valid = false;
	}

	return valid;
}
```

<br><br>
	
##	其他

*	注意，如果只有1个数是合格的，即`cnt==1`，输出时也要 `cout<<fixed<<setprecision(2)<<sum;`

	case2 是如下情况之一

	```
	sum1 = 12.00
	output1 ---> 12

	sum2 = 12.10
	output2 ---> 12.1
	```

*	[乙级链接](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1054_%E6%B1%82%E5%B9%B3%E5%9D%87%E5%80%BC)
