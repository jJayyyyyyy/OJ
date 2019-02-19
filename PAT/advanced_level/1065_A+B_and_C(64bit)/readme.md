本题题意有问题

如果完全按照题目描述的

```
Given three integers A, B and C in [−2^63, 2^63], you are supposed to tell whether A + B > C.
```

那么下面的代码应该是可用的, 因为 `double` 的范围足够包含 `[−2^63, 2^63]`

```cpp
#include <iostream>
using namespace std;

int main()
{
	double a, b, c;
	int n;
	cin >> n;
	for( int i = 1 ; i <= n ; i++ )
	{
		cin >> a >> b >> c;
		double sum = a + b;
		if( sum > c )
		{
			cout << "Case #" << i <<": true\n";
		}
		else
		{
			cout << "Case #" << i <<": false\n";
		}
	}
	return 0;
}
```

但是这段代码提交后的结果是全部错误, 说明题目中描述的 `[−2^63, 2^63]` 有问题

全部 AC 的代码如下, 各位看官可以对照一下其中的差异, 特别地, 当 a = b = 2^63 时, 两段代码结果不一样

```cpp
#include <iostream>
using namespace std;

int main()
{
	int n;
	long long a, b, c, sum;
	cin >> n;
	for( int i = 1; i <= n; i++ )
	{
		cin >> a >> b >> c;
		sum = a + b;
		if( a > 0 && b > 0 && sum < 0 )
		{
			// sum<0 means overflow
			// a + b > 2^63 >= c
			cout<<"Case #"<<i<<": true\n";
		}
		else if( a<0 && b<0 && sum>=0 )
		{
			// sum>=0 means overflow
			// a + b < -2^63 <= c
			cout<<"Case #"<<i<<": false\n";
		}
		else if( sum > c )
		{
			cout<<"Case #"<<i<<": true\n";
		}
		else
		{
			cout<<"Case #"<<i<<": false\n";
		}
	}

	return 0;
}
```
