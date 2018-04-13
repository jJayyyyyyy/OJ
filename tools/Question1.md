##	字符串/长整数

1.	反转

	*	Python

		```python
		a = 'hello'
		b = a[::-1]
		```
	
	*	C++

		```cpp
		string s1 = "hello";
		reverse(s4.begin(), s4.end());
		```

2.	切片/子串

	*	C++

		```cpp
		string s = "hello";
		s = s.substr(0, 2);
		// "he"
		// substr(start, length)
		// substr(起点, 长度)
		```

3.	str2num

	*	C++

		```cpp
		#include <string>
		#include <sstream>
		int str2num(string s){
			int num;
			stringstream ss;
			ss<<s;
			ss>>num;
			return num;
		}
		```

4.	错误提示

	*	Python 返回非零 --- 发生错误，比如除数为0，语法错误等等

	*	C++ 浮点错误 --- 一般是除数为0

##	其他

*	素数

	```cpp
	// 筛表法，找出MAXSIZE以内的素数，注意MAXSIZE应为奇数
	#define MAXSIZE 100005
	bool primeList[MAXSIZE] = {false, false, true};
	
	getPrimeList(){
		for( int i = 3; i < MAXSIZE; i += 2 ){
			primeList[i] = true;
			primeList[i + 1] = false;
		}
		
		int upperBound = (int) sqrt(MAXSIZE);
		for( int i = 3; i < upperBound; i += 2){
			if( primeList[i] == true ){
				for( int j = i + i; j < MAXSIZE; j += i ){
					primeList[j] = false;
				}
			}
		}
	}
	// 这样之后，若 primeList[i] == true ，则i是素数
	```

*	lcm, gcd

	```cpp
	// 最大公因数, the Greatest Common Divisor
	int get_gcd(int a, int b){
		if( b == 0 ){
			return a;
		}else{
			return get_gcd(b, a % b);
		}
	}
	
	// 最小公倍数, the Lowest Common Multiple
	int get_lcm(int a, int b){
		int gcd = get_gcd(a, b);
		// 注意除数不能为0
		if( gcd != 0 ){
			return a * b / gcd;
		}else{
			return 0;
		}
	}
	```

*	进制转换