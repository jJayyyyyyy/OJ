#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string num2str(int num)
{
	stringstream ss;
	ss << num;
	string str;
	ss >> str;
	return str;
}

string update_s(string str)
{
	int len = str.size();
	string ans = "";
	char ch = str[0];
	int pos = 0;
	for( int i = 0; i < len; i++ )
	{
		while( str[i] == ch )
		{
			i++;
		}
		ans += ch;
		ans += num2str(i - pos);
		pos = i;
		ch = str[i];
		i--;
	}
	return ans;
}

int main()
{
	string str;
	int n;

	cin >> str >> n;

	for( int i = 1; i < n; i++ )
	{
		str = update_s(str);
	}

	cout << str << '\n';
	return 0;
}
