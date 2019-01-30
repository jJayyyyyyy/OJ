#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
	stack<string> stk;

	string line;
	getline(cin, line);
	stringstream ss(line);

	while( !ss.eof() )
	{
		string str;
		getline(ss, str, ' ');
		stk.push(str);
	}

	cout<<stk.top();
	stk.pop();
	while( stk.size() != 0 )
	{
		cout<<' '<<stk.top();
		stk.pop();
	}

	return 0;
}