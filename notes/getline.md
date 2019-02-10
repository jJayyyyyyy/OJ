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
