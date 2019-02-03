#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	int bitmap[160] = {0};
	int len1 = s1.size();
	int len2 = s2.size();

	for( auto ch : s2 )
	{
		ch = toupper(ch);
		bitmap[ch]++;
	}

	for( auto ch : s1 )
	{
		ch = toupper(ch);
		if( bitmap[ch] == 0 )
		{
			cout<<ch;
			bitmap[ch]++;
		}
	}

	cout<<'\n';
	return 0;
}
