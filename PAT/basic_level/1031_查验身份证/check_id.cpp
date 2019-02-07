
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int weightList[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char checksum[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool checkID(string & id)
{
	int sum = 0;
	bool valid = true;
	for( int i = 0; i < 17; i++ )
	{
		char ch = id[i];
		if( isdigit(ch) == false )
		{
			valid = false;
			break;
		}
		else
		{
			sum += static_cast<int>(ch - '0') * weightList[i];
		}
	}

	if( valid == true )
	{
		int z = sum % 11;
		char ch1 = checksum[z];
		char ch2 = id[17];
		if( ch1 != ch2 )
		{
			valid = false;
		}
	}

	return valid;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string id;

	bool hasInvalid = false;
	for( int i = 0; i < n; i++ )
	{
		cin >> id;
		bool valid = checkID(id);
		if( valid == false )
		{
			hasInvalid = true;
			cout << id << '\n';
		}
	}

	if( hasInvalid == false )
	{
		cout<<"All passed\n";
	}

	return 0;
}
