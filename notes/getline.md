##	getline

*	Prototype, 原型

	```cpp
	istream & getline (istream & is, string & str, char delim);
	```

	<br>

*	示例

	```cpp
	#include <string>
	#include <iostream>
	#include <string>
	using namespace std;

	int main()
	{
		string line;
		getline(cin, line);
		stringstream ss(line);

		while( !ss.eof() )
		{
			string word;
			getline(ss, word, ' ');    // delim == ' '
		}

		return 0;
	}
	```

*	注意

	在使用 `getline` 真正的数据之前, 记得把 `cin` 遗留下来的空格全部读完

	```cpp
	// 输入
	// 3
	// 1 2 3
	// qwertyu iopasdd sfhjk 1234123123

	int main()
	{
		int n;
		cin >> n;
		char ch;
		for( int i = 0; i < n; i++ )
		{
			cin >> ch; // cin 会把空格放回输入缓冲区
		}
		string empty_line, line;
		getline(cin, empty_line); // 读取遗留的空格, 然后丢掉
		getline(cin, line);
		stringstream ss(line);
		while( !ss.eof() )
		{
			string word;
			getline( ss, word, ' ');
			// ...
		}
	}
	```